#include "utas.h"
#include <stdio.h>
#include <stdlib.h>

void emptyUtas(ListUtas *utas) {
    utas->neff = 0;
}

void isiUtas(ListUtas *utas, Word currentUser, ListDinkicau k, int id) {
    boolean ada = false;
    int n;
    Word temp;
    for (int i = 0; i < k.nEff; i++) {
        if (k.buffer[i].id == id) {
            ada = true;
            n = utas->neff;
            break;
        }
    }

    if (!ada) {
        printf("Tidak ada kicauan yang memiliki id berikut.\n");
        return;
    }


    for (int i = 0; i < k.nEff; i++) {
        if (k.buffer[i].id == id) {
            utas->utasan[n].k = k.buffer[i];
            break;
        }
    }

    if (!ceksama(utas->utasan[n].k.author, currentUser)) {
        printf("Utas hanya bisa dibuat untuk kicauan yang dibuat oleh pengguna itu sendiri.\n");
        return;
    }

    utas->utasan[n].u = (Address)malloc(sizeof(Utas));
    Address p = utas->utasan[n].u;

    printf("Utas berhasil dibuat!\n");
    printf("Masukkan kicauan:\n");
    temp = bacakalimat();
    p->isi = temp;
    p->date = ctow(DateTimeToString(CurrentDatetime()));
    p->next = NULL;

    char opt;
    printf("Apakah anda ingin melanjutkan utas ini? (Y/N)\n");
    temp = baca();
    opt = temp.TabWord[0];

    while (opt == 'y' || opt == 'Y') {
        p->next = (Address)malloc(sizeof(Utas));
        p = p->next;
        printf("Masukkan kicauan:\n");
        temp = bacakalimat();
        p->isi = temp;
        p->date = ctow(DateTimeToString(CurrentDatetime()));
        printf("Apakah anda ingin melanjutkan utas ini? (Y/N)\n");
        temp = baca();
        opt = temp.TabWord[0];
    }
    p->next = NULL;

    printf("Utas selesai!\n");
    utas->neff++;
}

void cetakUtas(ListUtas utas, ListDinkicau kicauan, UserDB user, Graf teman, int id, Word currentUser) {
    int i, idxkicau;
    boolean ada = false, berteman;
    Pengguna pembuatKicau;
    Pengguna currentPengguna;

    for (int a = 0; a < user.Neff; a++) {
        if (ceksama(currentUser, user.db[a].nama)) {
            currentPengguna = user.db[a];
            break;
        }
    }

    for (i = 0; i < utas.neff; i++) {
        if (utas.utasan[i].k.id == id) {
            ada = true;
            for (int a = 0; a < user.Neff; a++) {
                if (ceksama(utas.utasan[i].k.author, user.db[a].nama)) {
                    pembuatKicau = user.db[a];
                    break;
                }
            }
            break;
        } 
    }

    for (int a = 0; a < kicauan.nEff; a++) {
        if (kicauan.buffer[a].id == id) {
            idxkicau = a;
            break;
        }
    }

    if (!ada) {
        printf("Kicauan dengan id tersebut tidak memiliki utas.\n");
        return;
    }

    if (cekteman(currentPengguna, pembuatKicau, &user, teman)) {
        berteman = true;
    }

    if ((cek(kicauan.buffer[idxkicau].jakunkicau, "Publik") || (cek(kicauan.buffer[idxkicau].jakunkicau, "Privat") && berteman))) {
        printf("| ID = %d\n", id);
        printf("| ");
        for (int j = 0; j < utas.utasan[i].k.author.Length; j++) {
            printf("%c", utas.utasan[i].k.author.TabWord[j]);
        }
        printf("\n");
        printf("| ");
        for (int j = 0; j < utas.utasan[i].k.date.Length; j++) {
            printf("%c", utas.utasan[i].k.date.TabWord[j]);
        }
        printf("\n");
        printf("| ");
        for (int j = 0; j < utas.utasan[i].k.text.Length; j++) {
            printf("%c", utas.utasan[i].k.text.TabWord[j]);
        }
        printf("\n");    

        Address p = utas.utasan[i].u;
        int j = 1;

        while(p != NULL) {
            printf("\t| INDEX = %d\n", j);
            printf("\t| ");
            for (int k = 0; k < utas.utasan[i].k.author.Length; k++) {
                printf("%c", utas.utasan[i].k.author.TabWord[k]);
            }
            printf("\n");   
            printf("\t| ");
            for (int k = 0; k < p->date.Length; k++) {
                printf("%c", p->date.TabWord[k]);
            }
            printf("\n");   
            printf("\t| ");
            for (int k = 0; k < p->isi.Length; k++) {
                printf("%c", p->isi.TabWord[k]);
            }
            printf("\n");      
            j++;
            p = p->next;     
        }
    }

    else {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
    }
}

void sambungUtas(ListUtas *utas, int id, int indexParam, Word currentUser) {
    boolean ada = false;
    int i;
    int index = indexParam;
    for (i = 0; i < utas->neff; i++) {
        if (utas->utasan[i].k.id == id) {
            ada = true;
            break;
        }
    }

    if (!ada) {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    Address p = utas->utasan[i].u;
    while (index != 1 && ada) {        
        p = p->next;
        if (p == NULL) {
            ada = false;
        }
        index--;
    }

    if (!ada) {
        printf("Index terlalu tinggi!\n");
        return;
    }

    if (!ceksama(utas->utasan[i].k.author, currentUser)) {
        printf("Anda tidak bisa menyambung utas ini!\n");
        return;
    }

    Word temp;
    printf("Masukkan kicauan:\n");
    temp = bacakalimat();

    p = utas->utasan[i].u;
    Address newUtas = malloc(sizeof(Utas));
    newUtas->isi = temp;
    newUtas->date = ctow(DateTimeToString(CurrentDatetime()));
    newUtas->next = p;

    int tracker = indexParam;

    while (tracker != 1) {
        p = p->next;
        tracker--;
    }

    newUtas->next = p->next;
    p->next = newUtas;
    
    printf("Kicauan berhasil disambung!\n");
}

void hapusUtas(ListUtas *utas, int id, int indexParam, Word currentUser) {
    boolean ada = false;
    int i;
    int index = indexParam;
    for (i = 0; i < utas->neff; i++) {
        if (utas->utasan[i].k.id == id) {
            ada = true;
            break;
        }
    }

    if (!ada) {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    if (!ceksama(utas->utasan[i].k.author, currentUser)) {
        printf("Anda tidak bisa menghapus utas ini!\n");
        return;
    }  

    if (indexParam == 0) {
        printf("Anda tidak bisa menghapus kicauan utama!\n");
        return;
    }

    else if (indexParam == 1) {
        utas->utasan[i].u = utas->utasan[i].u->next;
        printf("Kicauan sambungan berhasil dihapus!\n");
        return;
    }

    // ketika index utas yg ingin dihapus adlh index 2 atau lebih

    Address p = utas->utasan[i].u;
    Address q = p->next;
    while (index != 2 && ada) {        
        q = q->next;
        p = p->next;
        if (q == NULL) {
            ada = false;
        }
        index--;
    }

    if (!ada) {
        printf("Index terlalu tinggi!\n");
        return;
    } 

    p->next = q->next;
    q = NULL;
    
    printf("Kicauan sambungan berhasil dihapus!\n");
}