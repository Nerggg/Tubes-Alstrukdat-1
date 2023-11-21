#include <stdio.h>
#include "draftkicauan.h"
#include "../feat/operational.h"


void CreateListDinStack(ListStack *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    l->buffer = (Stack *) malloc(capacity * sizeof(Stack));
    l->capacity = capacity;
    l->nEff = 0;
}

void dealocateListStack(ListStack *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(l->buffer);
    l->capacity = 0;
    l->nEff = 0;
}

void insertLastStack(ListStack *l, Stack S)
{
    l->buffer[l->nEff] = S;
    l->nEff++;
}


void CreateEmptyStack(Stack *S) {
    Top(*S) = Nil;
    S->Nstack = 0;
}

boolean IsEmptyStack(Stack S) {
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S) {
    return Top(S) == MaxEl-1;
}

void PushKicau(Stack * S, Kicau X) {
    Top(*S)++;
    InfoTop(*S) = X;
    S->Nstack++;
}

void PopKicau(Stack * S, Kicau* X) {
    *X = InfoTop(*S);
    Top(*S)--;
    S->Nstack--;
}


void BUAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau, ListStack *Sl)
{
    Pengguna currentPengguna;
    if (!cek(*currentUser, ";;;")) {
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            return;
        }
    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(user->db[i].nama, *currentUser)) {
            currentPengguna = user->db[i];
            break;
        }
    }
    Stack stackpengguna;
    boolean ada = false;
    for (int i = 0; i < Sl->nEff; i++) {
        if (ceksama(Sl->buffer[i].author, currentPengguna.nama)) {
            stackpengguna = Sl->buffer[i];
            ada = true;
            break;
        }
    }
    if (!ada){
        CreateEmptyStack(&stackpengguna);
        insertLastStack(Sl, stackpengguna);
        stackpengguna.author = currentPengguna.nama;
        
    }

    Word text;
    printf("Masukan draf: ");
    text = bacakalimat();

    // Validasi kicauan
    if (text.Length > 280) {
        printf("Kicauan tidak boleh lebih dari 280 karakter! Kicauan Anda akan terpotong secara otomatis.\n");
    } else{
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        // Membuat kicauan baru
        text = bacakalimat();
        boolean hapus = ceksama(text,ctow("HAPUS"));
        boolean terbit = ceksama(text,ctow("TERBIT"));
        boolean simpan = ceksama(text,ctow("SIMPAN"));
        Kicau newKicauan;
        int idx;
        for(idx = 0; idx < user->Neff; idx++) {
            if(ceksama(user->db[idx].nama, *currentUser)) {
                break;
            }
        }
        if (terbit){
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
        } else if(simpan){
            newKicauan.id = kicau->nEff;
            newKicauan.text = text;
            newKicauan.like = 0;
            newKicauan.author = user->db[idx].nama;
            newKicauan.date = ctow(DateTimeToString(CurrentDatetime()));
            newKicauan.jakunkicau = user->db[idx].jakun;
            PushKicau(&stackpengguna, newKicauan);
            printf("Draf telah berhasil disimpan!\n");
        }else if(hapus){
            return;
        }
    }
}
void LIHAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau, ListStack *Sl)
{
    Pengguna currentPengguna;
    if (!cek(*currentUser, ";;;")) {
            printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            return;
    }
    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(user->db[i].nama, *currentUser)) {
            currentPengguna = user->db[i];
            break;
        }
    }
    Stack stackpengguna;
    boolean ada = false;
    for (int i = 0; i < Sl->nEff; i++) {
        if (ceksama(Sl->buffer[i].author, currentPengguna.nama)) {
            stackpengguna = Sl->buffer[i];
            ada = true;
            break;
        }
    }
    if (IsEmptyStack(stackpengguna) || !ada){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else{
        Kicau kicauan = InfoTop(stackpengguna);
        printf("Ini draf terakhir anda:\n");
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
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        
        Word text;
        text = bacakalimat();
        boolean hapus = ceksama(text,ctow("HAPUS"));
        boolean terbit = ceksama(text,ctow("TERBIT"));
        boolean ubah = ceksama(text,ctow("UBAH"));
        boolean kembali = ceksama(text,ctow("KEMBALI"));
        if(hapus){
            PopKicau(&stackpengguna, &kicauan);
            printf("Draf telah berhasil dihapus!\n");
        }else if(terbit){
            if(kicau->capacity == kicau->nEff) {
                ListDinkicau tempkicau;
                copyListkicau(*kicau, &tempkicau);
                dealocateListkicau(kicau);
                CreateListDinkicau(kicau, tempkicau.capacity+1);
                for (int i = 0; i < tempkicau.capacity; i++) {
                    kicau->buffer[i] = tempkicau.buffer[i];
                }
            }
            PopKicau(&stackpengguna, &kicauan);
            
            insertLastkicau(kicau, kicauan);
            kicau->nEff++;
            // Mencetak kicauan
            printf("Kicauan Anda berhasil ditambahkan!\n");
            displaykicauan(kicauan);
        }else if(ubah){
            printf("Masukan draft yang baru: \n");
            text = bacakalimat();
            kicauan.text = text;
            kicauan.date = ctow(DateTimeToString(CurrentDatetime()));
            
            
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
            text = bacakalimat();
            boolean terbit = ceksama(text,ctow("TERBIT"));
            boolean simpan = ceksama(text,ctow("SIMPAN"));
            
            if(terbit){
                if(kicau->capacity == kicau->nEff) {
                ListDinkicau tempkicau;
                copyListkicau(*kicau, &tempkicau);
                dealocateListkicau(kicau);
                CreateListDinkicau(kicau, tempkicau.capacity+1);
                for (int i = 0; i < tempkicau.capacity; i++) {
                    kicau->buffer[i] = tempkicau.buffer[i];
                }
            }
                PopKicau(&stackpengguna, &kicauan);
                insertLastkicau(kicau, kicauan);
                kicau->nEff++;
                // Mencetak kicauan
                printf("Kicauan Anda berhasil ditambahkan!\n");
                displaykicauan(kicauan);
            }else if (simpan){
                printf("Draf telah berhasil disimpan!\n");
                return;
            }
        }else if (kembali){
            return;
        }
    }
}
