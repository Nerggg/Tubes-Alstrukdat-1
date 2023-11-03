#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "pengguna.h"
#include "datetime.h"
#include "listdin.h"

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




#endif