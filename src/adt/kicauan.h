#ifndef KICAU_H
#define KICAU_H

#include "boolean.h"
#include "pengguna.h"
#include "datetime.h"
#include "teman.h"
#include "../feat/operational.h"
#include "../feat/misc.h"

// Definisi tipe data kicauan
typedef struct {
	int id;
	Word text;
	int like;
	Word author;
	Word date;
	Word jakunkicau;
} Kicau;

typedef struct node* Addresst;
typedef  struct node
{
    Kicau value; // nilai node
    Addresst firstChild; // pointer ke anak.
    Addresst nextSibling; // pointer ke saudara.
} Tree;

#define value(p) (p)->value
#define firstChild(p) (p)->firstChild
#define nextSibling(p) (p)->nextSibling
#define root(t) (t)

Addresst newNodet(Kicau val);

typedef Addresst List;

typedef struct
{
    Kicau *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDinkicau;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).CAPACITY

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

typedef struct
{
    List *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDintree;

/* ********** SELEKTOR ********** */
#define NEFFtr(l) (l).nEff
#define BUFFERtr(l) (l).buffer
#define ELMTtr(l, i) (l).buffer[i]
#define CAPACITYTr(l) (l).capacity


void CreateListoftree(ListDintree *l, int capacity);
void dealocatelistoftree(ListDintree *l);
void insertLasttree(ListDintree *l, List newtree);
void deleteAt(ListDintree *t, int idToDelete) ;
void deleteLasttree(ListDintree *l, List *lastree);
void copylisttree(ListDintree lIn, ListDintree *lOut);
List searchidxtree(ListDintree l, int id);
boolean cektree(ListDintree l, int id);

void CreateTree(List *t);

void CreateListDinkicau(ListDinkicau *l, int capacity);
void dealocateListkicau(ListDinkicau *l);
void printListkicau(ListDinkicau l);
void copyListkicau(ListDinkicau lIn, ListDinkicau *lOut);
void insertLastkicau(ListDinkicau *l, Kicau newkicauan);
void deleteLastkicau(ListDinkicau *l, Kicau *kicauantemp);
void kicau(UserDB *user, ListDinkicau *kicau, Word *currentUser, ListDintree *ltree);
void displaykicauan(Kicau);
void suka_kicauan(UserDB user, ListDinkicau *kicau, Graf teman, int id, Word currentUser);
void ubah_kicauan(UserDB user, ListDinkicau *kicau, int id, Word currentUser);
void displayallkicauan(UserDB user, ListDinkicau kicauan, Graf teman, Word currentUser);
Pengguna cariuser(UserDB user, Word kata);

#endif
