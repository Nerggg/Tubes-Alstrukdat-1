#ifndef BALASAN_H
#define BALASAN_H

#include "datetime.h"
#include "wordmachine.h"
#include "kicauan.h"

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

#define IDX_UNDEF (-1)

typedef struct
{
    List *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDintree;

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListoftree(ListDintree *l, int capacity);

void dealocatelistoftree(ListDintree *l);

void insertLasttree(ListDintree *l, List newtree);

void deleteLasttree(ListDintree *l, List *lastree);

List searchidxtree(ListDintree l, int id);

/* PROTOTYPE */    
void CreateTree(List *t);

void addChild(List *t,Kicau val);

void addSibling(List *t, Kicau val);

void deleteChild(List *t, int id);

int countValuesInTree(Addresst node);

void addBalasan(List *t, int id);

int findLargestIdx(Addresst root, int *largestValue);

void Balas(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree,Graf teman, int idkicau, int idbalasan);

void Balasan(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree,Graf teman, int idkicau);

void Hapus_Balasan(UserDB *user,Word *currentUser,ListDinkicau *kicau,ListDintree *kumpulantree, int idkicau, int idbalasan);

#endif