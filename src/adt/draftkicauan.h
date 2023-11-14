#ifndef DRAFTKICAU_H
#define DRAFTKICAU_H

#include <stdio.h>
#include "kicauan.h"

#define Nil -1
#define MaxEl 100

typedef int address;   /* indeks tabel */

typedef struct { 
  Kicau T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);

boolean IsFull(Stack S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, Kicau X);

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, Kicau* X);

void BUAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau);
void LIHAT_DRAFT(UserDB *user,Word *currentUser, ListDinkicau *kicau);


#endif