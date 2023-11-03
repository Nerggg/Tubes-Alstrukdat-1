#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "pengguna.h"
#include "datetime.h"
#include "listlinier.h"


// Konstanta
#define MAX_Length_text 280 //termasuk tanda baca dan spasi

// Definisi tipe data kicauan
typedef struct {
	int id;
	Word text;
	int like;
	Word author;
	DATETIME datetime;
} Kicau;

typedef struct node* Address;
typedef struct listkicau {
    Kicau info;
    struct listkicau* next; 
} listkicau;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

Address newNodekicau(Kicau kicauanlokasibaru);
void insertKicauanFirst(listkicau *kicauan, Kicau kicauanbaru);
void kicau(Word *currentUser);
List kicauan(List kicauan);
Kicau displaykicauan(Kicau *kicauan);
Kicau suka_kicauan(int id);
void ubah_kicauan(int id);

#endif