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

ListStack increaseSizeListStack(ListStack l) {
    ListStack output;
    CreateListDinStack(&output, l.nEff+1);
    for (int i = 0; i < output.nEff; i++) {
        output.buffer[i] = l.buffer[i];
    }
    return output;
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
    *X = S->T[S->TOP];
    Top(*S)--;
    S->Nstack--;
}


void BUAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau, ListStack *Sl)
{
    Pengguna currentPengguna;
    if (cek(*currentUser, ";;;")) {
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
    int indexstack = -1;
    boolean ada = false;
    for (int i = 0; i < Sl->nEff; i++) {
        if (ceksama(Sl->buffer[i].author, currentPengguna.nama)) {
            stackpengguna = Sl->buffer[i];
            ada = true;
            indexstack = i;
            break;
        }
    }
    if (!ada){
        CreateEmptyStack(&stackpengguna);
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
        Word opt = baca();;
        Word HAPUS = {"HAPUS", 5};
        Word TERBIT = {"TERBIT", 6};
        Word SIMPAN = {"SIMPAN", 6};
        boolean hapus = ceksama(opt,HAPUS);
        boolean terbit = ceksama(opt,TERBIT);
        boolean simpan = ceksama(opt,SIMPAN);
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
                    kicau->nEff++;
                }

            }

            newKicauan.id = kicau->nEff+1;
            newKicauan.text = text;
            newKicauan.like = 0;
            newKicauan.author = user->db[idx].nama;
            newKicauan.date = ctow(DateTimeToString(CurrentDatetime()));
            newKicauan.jakunkicau = user->db[idx].jakun;

            kicau->buffer[kicau->nEff] = newKicauan;
            kicau->nEff++;

            // Mencetak kicauan
            printf("Kicauan Anda berhasil ditambahkan!\n");
            displaykicauan(newKicauan);
        } else if(simpan){
            newKicauan.id = kicau->nEff+1;
            newKicauan.text = text;
            newKicauan.like = 0;
            newKicauan.author = user->db[idx].nama;
            newKicauan.date = ctow(DateTimeToString(CurrentDatetime()));
            newKicauan.jakunkicau = user->db[idx].jakun;
            PushKicau(&stackpengguna, newKicauan);

            if (Sl->capacity == Sl->nEff) {
                *Sl = increaseSizeListStack(*Sl);
            }

            if (indexstack != -1) {
                printf("masuk kesini\n");
                Sl->buffer[indexstack] = stackpengguna;
            }
            else { // untuk kondisi ketika draft suatu akun belum ada
                // printf("s1 neff nya %d\n", Sl->nEff);
                printf("atau kebawah\n");
                Sl->buffer[Sl->nEff] = stackpengguna;
                Sl->nEff++;
            }
            // printf("ada di %s\n", Sl->buffer[Sl->nEff].T[0].text.TabWord);  

            printf("Draf telah berhasil disimpan!\n");
        }else if(hapus){
            printf("Draf berhasil dihapus!\n");
            return;
        }
    }
}
void LIHAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau, ListStack *Sl)
{
    int indexstack;
    Pengguna currentPengguna;
    if (cek(*currentUser, ";;;")) {
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
        // printf("teksnya pas i nya %d adalah %s\n", i, Sl->buffer[i].T[Sl->buffer[i].TOP].text.TabWord);
        if (ceksama(Sl->buffer[i].author, currentPengguna.nama)) {
            stackpengguna = Sl->buffer[i];
            ada = true;
            indexstack = i;
            break;
        }
    }
    if (IsEmptyStack(stackpengguna) || !ada){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else{
        Kicau kicauan = stackpengguna.T[stackpengguna.TOP];
        printf("Ini draf terakhir anda:\n");
        printf("indexnya %d\n", stackpengguna.TOP);
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
        
        Word opt;
        opt = baca();
        Word HAPUS = {"HAPUS", 5};
        Word TERBIT = {"TERBIT", 6};
        Word UBAH = {"UBAH", 4};
        Word KEMBALI = {"KEMBALI", 7};
        Word SIMPAN = {"SIMPAN", 6};
        boolean hapus = ceksama(opt,HAPUS);
        boolean terbit = ceksama(opt,TERBIT);
        boolean ubah = ceksama(opt,UBAH);
        boolean kembali = ceksama(opt,KEMBALI);
        if(hapus){
            PopKicau(&stackpengguna, &kicauan);
            Sl->buffer[indexstack] = stackpengguna;
            printf("Draf telah berhasil dihapus!\n");
        }else if(terbit){
            if(kicau->capacity == kicau->nEff) {
                ListDinkicau tempkicau;
                copyListkicau(*kicau, &tempkicau);
                dealocateListkicau(kicau);
                CreateListDinkicau(kicau, tempkicau.capacity+1);
                for (int i = 0; i < tempkicau.capacity; i++) {
                    kicau->buffer[i] = tempkicau.buffer[i];
                    kicau->nEff++;
                }
            }
            PopKicau(&stackpengguna, &kicauan);
            kicauan.id = kicau->nEff+1;
            kicau->buffer[kicau->nEff] = kicauan;
            kicau->nEff++;

            Sl->buffer[indexstack] = stackpengguna;
            // Mencetak kicauan
            printf("Kicauan Anda berhasil ditambahkan!\n");
            displaykicauan(kicauan);
        }else if(ubah){
            printf("Masukan draft yang baru: \n");
            Word text = bacakalimat();
            kicauan.text = text;
            kicauan.date = ctow(DateTimeToString(CurrentDatetime()));
            
            
            printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
            opt = baca();
            boolean terbit = ceksama(opt,TERBIT);
            boolean simpan = ceksama(opt,SIMPAN);
            
            if(terbit){
                if(kicau->capacity == kicau->nEff) {
                ListDinkicau tempkicau;
                copyListkicau(*kicau, &tempkicau);
                dealocateListkicau(kicau);
                CreateListDinkicau(kicau, tempkicau.capacity+1);
                for (int i = 0; i < tempkicau.capacity; i++) {
                    kicau->buffer[i] = tempkicau.buffer[i];
                    kicau->nEff++;
                }
            }
                stackpengguna.T[stackpengguna.TOP] = kicauan;
                PopKicau(&stackpengguna, &kicauan);
                kicauan.id = kicau->nEff+1;
                kicau->buffer[kicau->nEff] = kicauan;
                kicau->nEff++;
                // Mencetak kicauan

                Sl->buffer[indexstack] = stackpengguna;
                printf("Kicauan Anda berhasil ditambahkan!\n");
                displaykicauan(kicauan);
            }else if (simpan){
                stackpengguna.T[stackpengguna.TOP] = kicauan;
                Sl->buffer[indexstack] = stackpengguna;
                printf("Draf telah berhasil disimpan!\n");
                return;
            }
        }else if (kembali){
            return;
        }
    }
}
