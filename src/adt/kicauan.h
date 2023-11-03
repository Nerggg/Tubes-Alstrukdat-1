#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "pengguna.h"
#include "datetime.h"
#include "listdinkicauan.h"

// Definisi tipe data kicauan
typedef struct {
	int id;
	Word text;
	int like;
	Word author;
	DATETIME datetime;
} Kicau;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void kicau(Word *currentUser);
Kicau displaykicauan(Kicau *kicauan);
Kicau suka_kicauan(int id);
void ubah_kicauan(int id);




#endif