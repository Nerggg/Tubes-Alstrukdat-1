#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "boolean.h"
#include "wordmachine.h"

typedef struct { 
	Word nama;
	Word pass;
	Word bio;
	Word hp;
	Word weton;
	Word jakun;
	char pp[5][10];
} Pengguna;

typedef struct { 
	Pengguna db[20];
} UserDB;

#endif
