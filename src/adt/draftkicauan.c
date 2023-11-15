#include <stdio.h>
#include "draftkicauan.h"
#include "../feat/operational.c"
#include "../feat/io.c"


void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S) {
    return Top(S) == Nil;
}

boolean IsFull(Stack S) {
    return Top(S) == MaxEl-1;
}

void Push(Stack * S, Kicau X) {
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack * S, Kicau* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}

Stack draft;

void BUAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau)
{
    
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
            Push(&draft, newKicauan);
            printf("Draf telah berhasil disimpan!\n");
        }
    }

    
    
}
void LIHAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau)
{
    if (IsEmpty(draft)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else{
        Kicau kicauan = InfoTop(draft);
        printf("Ini draf terakhir anda:\n");
        printf("| %s\n", kicauan.date);
        printf("| %s\n", kicauan.text);
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        
        Word text;
        text = bacakalimat();
        boolean hapus = ceksama(text,ctow("HAPUS"));
        boolean terbit = ceksama(text,ctow("TERBIT"));
        boolean ubah = ceksama(text,ctow("UBAH"));
        boolean kembali = ceksama(text,ctow("KEMBALI"));
        if(hapus){
            Pop(&draft, &kicauan);
            printf("Draf telah berhasil dihapus!\n");
        }else if(terbit){
            reateListDinkicau(&kicau, 100);
            insertLastkicau(&kicau, kicauan);
            // Mencetak kicauan
            printf("Kicauan Anda berhasil ditambahkan!\n");
            displaykicauan(kicauan);
            Pop(&draft, &kicauan);
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
                CreateListDinkicau(&kicau, 100);
                insertLastkicau(&kicau, kicauan);
                // Mencetak kicauan
                printf("Kicauan Anda berhasil ditambahkan!\n");
                displaykicauan(kicauan);
                Pop(&draft, &kicauan);
            }else if (simpan){
                printf("Draf telah berhasil disimpan!\n");
            }

        }else if (kembali){
            
        }
    }
}
