#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

void CreateListDinkicau(ListDinkicau *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    l->buffer = (Kicau *) malloc(capacity * sizeof(Kicau));
    l->capacity = capacity;
    l->nEff = 0;
}

void dealocateListkicau(ListDinkicau *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(l->buffer);
    l->capacity = 0;
    l->nEff = 0;
}

void printListkicau(ListDinkicau l)
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    for (i = 0; i < l.nEff; i++) {
        displaykicauan(l.buffer[i]);
    }
}

void copyListkicau(ListDinkicau lIn, ListDinkicau *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    IdxType i;

    /* ALGORITMA */
    CreateListDinkicau(lOut, lIn.capacity);

    lOut->capacity = lIn.nEff;

    for (i = 0; i < lIn.nEff; i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

void insertLastkicau(ListDinkicau *l, Kicau newkicauan)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = newkicauan;
    NEFF(*l)++;
}

void deleteLastkicau(ListDinkicau *l, Kicau *kicauantemp)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *kicauantemp = ELMT(*l, NEFF(*l));
    NEFF(*l)--;
}

void kicau(UserDB *user, ListDinkicau *kicau, Word *currentUser)
{
    if (!cek(*currentUser, ";;;")) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    int idx;
    for(idx = 0; idx < user->Neff; idx++) {
        if(ceksama(user->db[idx].nama, *currentUser)) {
            break;
        }
    }

    // Mengambil input dari pengguna
    Word text;
    printf("Ketik kicauan Anda: ");
    text = bacakalimat();

    // Validasi kicauan
    if (text.Length > 280) {
        printf("Kicauan tidak boleh lebih dari 280 karakter! Kicauan Anda akan terpotong secara otomatis.\n");
    }

    // Membuat kicauan baru
    Kicau newKicauan;
    if(kicau->capacity == kicau->nEff) {
        ListDinkicau tempkicau;
        copyListkicau(*kicau, &tempkicau);
        dealocateListkicau(kicau);
        CreateListDinkicau(kicau, tempkicau.capacity+1);
        for (int i = 0; i < tempkicau.capacity; i++) {
            kicau->buffer[i] = tempkicau.buffer[i];
        }

    }

    newKicauan.id = kicau->nEff;
    newKicauan.text = text;
    newKicauan.like = 0;
    newKicauan.author = user->db[idx].nama;
    newKicauan.date = ctow(DateTimeToString(CurrentDatetime()));
    newKicauan.jakunkicau = user->db[idx].jakun;

    insertLastkicau(kicau, newKicauan);
    kicau->nEff++;

    // Mencetak kicauan
    printf("Kicauan Anda berhasil ditambahkan!\n");
    displaykicauan(newKicauan);
}

void displaykicauan(Kicau kicauan)
{    
    printf("| ID = %d\n", kicauan.id);
    printf("| ");
    for (int i = 0; i < kicauan.author.Length; i++) {
        printf("%c", kicauan.author.TabWord[i]);
    }
    printf("\n");
    printf("| ");
    for (int i = 0; i < kicauan.date.Length; i++) {
        printf("%c", kicauan.date.TabWord[i]);
    }
    printf("\n");
    printf("| ");
    for (int i = 0; i < kicauan.text.Length; i++) {
        printf("%c", kicauan.text.TabWord[i]);
    }
    printf("\n");
    printf("| Disukai: %d\n", kicauan.like);
}



void suka_kicauan(UserDB user, ListDinkicau *kicau, Graf teman, int id, Word currentUser)
{
    boolean berteman = false;
    Pengguna currentPengguna;
    Pengguna pembuatKicau;
    int idx;
    for (int i = 0; i < user.Neff; i++) {
        if (ceksama(user.db[i].nama, currentUser)) {
            currentPengguna = user.db[i];
            break;
        }
    }

    for (int i = 0; i < kicau->nEff; i++) {
        if (kicau->buffer[i].id == id) {
            idx = i;
            for (int j = 0; j < user.Neff; j++) {
                if(ceksama(user.db[j].nama, kicau->buffer[i].author)) {
                    pembuatKicau = user.db[j];
                    break;
                }
            }
            if(cekteman(currentPengguna, pembuatKicau, &user, teman)) {
                berteman = true;
                break;
            }
            break;
        }
    }

    if ((cekKata(kicau->buffer[idx].jakunkicau, "Publik") || cekKata(kicau->buffer[idx].jakunkicau, "Privat")) && berteman) {
        kicau->buffer[idx].like++;
        printf("Selamat! kicauan telah disukai!\n");
        printf("Detil kicauan:\n");
        displaykicauan(kicau->buffer[idx]);
    }

    else {
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
    }
}

void ubah_kicauan(UserDB user, ListDinkicau *kicau, int id, Word currentUser)
{
    int idx;
    for (int i = 0; i < kicau->nEff; i++) {
        if (kicau->buffer[i].id == id) {
            idx = id;
            for (int j = 0; j < user.Neff; j++) {
                if(!ceksama(user.db[j].nama, kicau->buffer[i].author)) {
                    printf("Kicauan dengan id %d bukan milikmu!\n", id);
                    return;
                }
        }
    }

    Word temp;
    printf("Masukkan kicauan baru:\n");
    temp = bacakalimat();

    kicau->buffer[idx].text = temp;
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displaykicauan(kicau->buffer[idx]);
    }
}
