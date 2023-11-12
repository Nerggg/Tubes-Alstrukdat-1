#include<stdio.h>
#include <stdlib.h>
#include "kicauan.h"
#include "../feat/operational.c"
#include "../feat/misc.c"


ListDinkicau kicauanku;
int lastIDKicau;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinkicau(ListDinkicau *l, int cap)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (Kicau *) malloc(cap * sizeof(Kicau));
    CAPACITY(*l) = cap;
    NEFF(*l) = 0;
}

void dealocateListkicau(ListDinkicau *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** OPERASI LAIN ********** */
void copyListkicau(ListDinkicau lIn, ListDinkicau *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{

    /* ALGORITMA */
    CreateListDinkicau(lOut, CAPACITY(lIn));

    NEFF(*lOut) = lIn.neff;

    for (int i = 0; i <= NEFF(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastkicau(ListDinkicau *l, Kicau newkicauan)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l) + 1) = newkicauan;
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
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

ListDinkicau *cariKicauan(ListDinkicau *l,int id)
{
    ListDinkicau *lKicau = NULL;

  
    for (int i = 0; i < NEFF(*l); i++) {
        if ((*l).buff[i].id == id) {
            lKicau = (ListDinkicau *)l->buff;
            break;
        }
    }

    return lKicau;
}

void kicau(UserDB *user,Word *currentUser)
{
    if (!cek(*currentUser, ";;;")) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
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
    CreateListDinkicau(&kicauanku, 100);
    insertLastkicau(&kicauanku, newKicauan);
    newKicauan.id = kicauanku.neff;
    newKicauan.text = text;
    newKicauan.like = 0;
    newKicauan.author = user->db[0].nama;
    newKicauan.datetime = CurrentDatetime();
    newKicauan.jakunkicau = user->db[0].jakun;

    // Mencetak kicauan
    printf("Kicauan Anda berhasil ditambahkan!\n");
    displaykicauan(&newKicauan);
}

Kicau displaykicauan(Kicau *kicauan)
{
    printf("| ID = %d\n", kicauan->id);
    printf("| %s\n", kicauan->author);
    printf("| %s\n", DateTimeToString(kicauan->datetime)); 
    printf("| %s\n", kicauan->text);
    printf("| Disukai: %d\n", kicauan->like);
}



Kicau suka_kicauan(UserDB *user,int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
    } else{
        if (cekKata(lKicau->buff[0].jakunkicau,"Publik")) {  
       printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }else{
        lKicau->buff[0].like++;
        displaykicauan(lKicau->buff);}
    }
}

void ubah_kicauan(UserDB *user,int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
        return;
    }

    for (int i = 0; i < lKicau->neff; i++) {
        Kicau ubahkicau = lKicau->buff[i];
    }

    
    if (ceksama((lKicau->buff[0].author),(user->db[0].nama))) {
    printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
    return;
    }


    // Masukkan kicauan baru
    printf("Masukkan kicauan baru: ");
    lKicau->buff[0].text = bacakalimat();


    // Cetak informasi kicauan yang baru diubah
    printf("Selamat! kicauan telah diterbitkan!\n");
    displaykicauan(lKicau->buff);
}


