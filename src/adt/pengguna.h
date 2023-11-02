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
	MATRIX PP;
} Pengguna;

typedef struct { 
	Pengguna db[20];
	int Neff;
} UserDB;

void emptyuser(Word*);

void daftar(UserDB*, Word*);
/*I.S. Pengguna belum terdaftar dan dalam keadaan belum melakukan login*/
/*F.S. Pengguna terdaftar dengan nama unik beserta password antar pengguna */
/*Ketika pengguna pertama kali melakukan instruksi daftar, pengguna belum memiliki teman*/

void masuk(UserDB*, Word*);
/*I.S. Pengguna mungkin belum terdaftar*/
/*F.S. Pengguna berhasil masuk dan menjalankan perintah lain dengan masukan nama dan password yang sesuai */
/*Sebelum melakukan masuk, pengguna tidak dapat melakukan akses ke perintah apapun selain masuk, daftar, tutup_program, dan muat.*/


void keluar(Word*);
/*I.S. Pengguna mungkin dalam keadaan belum login (harusnya dalam keadaan login)*/
/*F.S. Pengguna berhasil keluar */


#endif
