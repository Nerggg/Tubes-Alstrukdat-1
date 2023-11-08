#include <stdio.h>
#include "listdinkicauan.h"



/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinkicau(ListDinkicau *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (Kicau *) malloc(capacity * sizeof(Kicau));
    CAPACITY(*l) = capacity;
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

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void printListkicau(ListDinkicau l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    for (i = 0; i <= getLastIdx(l); i++) {
        displaykicauan(l.buffer);
    }
}


/* ********** OPERASI LAIN ********** */
void copyListkicau(ListDinkicau lIn, ListDinkicau *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));

    NEFF(*lOut) = listLength(lIn);

    for (i = 0; i <= getLastIdx(lIn); i++) {
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
    ELMT(*l, getLastIdx(*l) + 1) = newkicauan;
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
    *kicauantemp = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

ListDinkicau *cariKicauan(ListDinkicau *l,int id)
{
    ListDinkicau *lKicau = NULL;

  
    for (int i = 0; i < NEFF(*l); i++) {
        if ((*l).buffer[i].id == id) {
            lKicau = &l;
            break;
        }
    }

    return lKicau;
}