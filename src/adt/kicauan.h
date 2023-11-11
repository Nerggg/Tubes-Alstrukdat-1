#ifndef KICAU_H
#define KICAU_H

#include <stdio.h>
#include "pengguna.h"
#include "datetime.h"

// Definisi tipe data kicauan
typedef struct {
	int id;
	Word text;
	int like;
	Word author;
	DATETIME datetime;
	Word jakunkicau;
} Kicau;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void kicau(UserDB *user,Word *currentUser);
Kicau displaykicauan(Kicau *kicauan);
Kicau suka_kicauan(UserDB *user,int id);
void ubah_kicauan(UserDB *user,int id);




#endif