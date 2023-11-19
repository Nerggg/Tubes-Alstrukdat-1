#ifndef UTAS_H
#define UTAS_H

#include "boolean.h"
#include "wordmachine.h"
#include "../feat/operational.h"
#include "../feat/misc.h"
#include "kicauan.h"
#include "datetime.h"

typedef struct utas* Address;
typedef struct utas { 
	Word isi;
	Word date;	
	Address next;
} Utas;

typedef struct {
	Kicau k;
	Address u;
} KicauUtas;

typedef struct {
	KicauUtas utasan[100];
	int neff; // banyaknya kicauan yang memiliki utas
} ListUtas; 

void emptyUtas(ListUtas *utas);
void isiUtas(ListUtas *utas, Word currentUser, ListDinkicau k, int id);
void cetakUtas(ListUtas utas, ListDinkicau kicauan, UserDB user, Graf teman, int id, Word currentUser);
void sambungUtas(ListUtas *utas, int id, int indexParam, Word currentUser);
void hapusUtas(ListUtas *utas, int id, int indexParam, Word currentUser);

#endif
