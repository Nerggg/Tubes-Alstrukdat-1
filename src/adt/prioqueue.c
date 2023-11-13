#include "prioqueue.h"
#include "pengguna.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmptyPrio(prioqueuefren Q) {
    return HeadQ(Q) == Nil;
}

boolean IsFullPrio(prioqueuefren Q) {
    return NBElmtPrio(Q) == MaxElQ(Q);
}

int NBElmtPrio(prioqueuefren Q) {
    if (IsEmptyPrio(Q)) {
        return 0;
    }
    if (HeadQ(Q) <= TailQ(Q)) {
        return TailQ(Q) - HeadQ(Q) + 1;
    } else {
        return MaxElQ(Q) - HeadQ(Q) + TailQ(Q) + 2;
    }
}

void MakeEmptyprio(prioqueuefren *Q, int Max) {
    (*Q).T = (teman *)malloc((Max + 1) * sizeof(teman));
    if ((*Q).T != NULL) {
        MaxElQ(*Q) = Max;
        HeadQ(*Q) = Nil;
        TailQ(*Q) = Nil;
    } else {
        MaxElQ(*Q) = 0;
    }
}

void DeAlokasiprio(prioqueuefren *Q) {
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

void Enqueueprio(prioqueuefren *Q, teman t) {
    if (IsEmptyPrio(*Q)) {
        HeadQ(*Q) = 0;
        TailQ(*Q) = 0;
        ElmtQ(*Q, 0) = t;
    } else {
        addressPrioqueue i = TailQ(*Q);
        while (i != Nil && t.Jumlahteman < ElmtQ(*Q, i).Jumlahteman) {
            ElmtQ(*Q, (i + 1) % (MaxElQ(*Q) + 1)) = ElmtQ(*Q, i);
            i = (i - 1 + MaxElQ(*Q) + 1) % (MaxElQ(*Q) + 1);
        }
        i = (i + 1) % (MaxElQ(*Q) + 1);
        ElmtQ(*Q, i) = t;
        TailQ(*Q) = (TailQ(*Q) + 1) % (MaxElQ(*Q) + 1);
    }
}

void Dequeueprio(prioqueuefren *Q, teman *t) {
    *t = InfoHeadQ(*Q);
    if (HeadQ(*Q) == TailQ(*Q)) {
        HeadQ(*Q) = Nil;
        TailQ(*Q) = Nil;
    } else {
        HeadQ(*Q) = (HeadQ(*Q) + 1) % (MaxElQ(*Q) + 1);
    }
}

void Enqueueuserprio(prioqueuefren Q, int IDuser, prioqueuefren *Quser, prioqueuefren *Qsisa) {
    MakeEmptyprio(Quser, MaxElQ(Q));
    MakeEmptyprio(Qsisa, MaxElQ(Q));

    teman t;
    while (!IsEmptyPrio(Q)) {
        Dequeueprio(&Q, &t);
        if (t.IDpenerima == IDuser) {
            Enqueueprio(Quser, t);
        } else {
            Enqueueprio(Qsisa, t);
        }
    }
}

void concatenationprio(prioqueuefren Quser, prioqueuefren Qsisa, prioqueuefren *Q) {
    MakeEmptyprio(Q, MaxElQ(Quser) + MaxElQ(Qsisa));

    while (!IsEmptyPrio(Quser)) {
        teman t;
        Dequeueprio(&Quser, &t);
        Enqueueprio(Q, t);
    }

    while (!IsEmptyPrio(Qsisa)) {
        teman t;
        Dequeueprio(&Qsisa, &t);
        Enqueueprio(Q, t);
    }
}

void PrintTopPrioQueueChar(prioqueuefren quser, int idAkun, UserDB listakun, int *idteman) {
    if (IsEmptyPrio(quser)) {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
    else{
        teman topTeman;
        Dequeueprio(&quser, &topTeman);

        *idteman = topTeman.IDpengirim;

        printf("Permintaan pertemanan teratas dari %s\n", listakun.db[*idteman].nama.TabWord);
        printf("| %s\n", listakun.db[*idteman].nama.TabWord);
        printf("| Jumlah teman: %d\n", topTeman.Jumlahteman);
        }
}

void PrintPrioQueue(prioqueuefren quser, UserDB listakun) {
    if (IsEmptyPrio(quser)) {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
        return;
    }

    printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmtPrio(quser));

    addressPrioqueue i = HeadQ(quser);

    do {
        teman t = ElmtQ(quser, i);

        // Process additional information using UserDB for the sender (assuming you have it)
        
        printf("| %s\n", listakun.db[i].nama.TabWord);
        printf("| Jumlah Teman: %d\n", t.Jumlahteman);
        printf("\n");

        i = (i + 1) % (MaxElQ(quser) + 1);
    } while (i != (TailQ(quser) + 1) % (MaxElQ(quser) + 1));
}

