#include "utas.h"
#include <stdlib.h>

void emptyUtas(ListUtas *utas) {
    utas->neff = 0;
}

void isiUtas(ListUtas *utas, Word currentUser, ListDinkicau k, int id) {
    boolean ada = false;
    int n;
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

    Address p = utas->utasan[n].u;

    Word temp;        
    printf("Utas berhasil dibuat!\n");
    printf("Masukkan kicauan:\n");
    p->isi = bacakalimat();
    p->date = ctow(DateTimeToString(CurrentDatetime()));
    p->next = NULL;

    char opt;
    printf("Apakah anda ingin melanjutkan utas ini? (Y/N)\n");
    scanf("%c", &opt);

    while (opt == 'y' || opt == 'Y') {
        p = p->next;
        p->next = NULL;
        printf("Masukkan kicauan:\n");
        p->isi = bacakalimat();
        p->date = ctow(DateTimeToString(CurrentDatetime()));
        printf("Apakah anda ingin melanjutkan utas ini? (Y/N)\n");
        scanf("%c", &opt);
    }

    printf("Utas selesai!\n");
    utas->neff++;
}

void cetakutas(ListUtas utas, int id) {
    int i;
    boolean ada = false;
    for (i = 0; i < utas.neff; i++) {
        if (utas.utasan[i].k.id == id) {
            ada = true;
            break;
        } 
    }

    if (!ada) {
        printf("Kicauan dengan id tersebut tidak memiliki utas.\n");
        return;
    }

    printf("| ID = %d\n", id);
    printf("| ");
    for (int j = 0; j < utas.utasan[i].k.author.Length; j++) {
        printf("%c", utas.utasan[i].k.author.TabWord[j]);
    }
    printf("\n");
    printf("| %s\n", utas.utasan[i].k.datetime);
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