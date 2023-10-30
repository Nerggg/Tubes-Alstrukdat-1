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
	int status; //pengguna sudah login status == 1; pengguna belum login status == 0;
} Pengguna;

typedef struct { 
	Pengguna db[20];
} UserDB;

#define MAX_USER 20

UserDB user;
int jumlah_pengguna = 0;


void daftar();
/*I.S. Pengguna belum terdaftar dan dalam keadaan belum melakukan login*/
/*F.S. Pengguna terdaftar dengan nama unik beserta password antar pengguna */
/*Ketika pengguna pertama kali melakukan instruksi daftar, pengguna belum memiliki teman*/


void masuk();
/*I.S. Pengguna mungkin belum terdaftar*/
/*F.S. Pengguna berhasil masuk dan menjalankan perintah lain dengan masukan nama dan password yang sesuai */
/*Sebelum melakukan masuk, pengguna tidak dapat melakukan akses ke perintah apapun selain masuk, daftar, tutup_program, dan muat.*/


void keluar();
/*I.S. Pengguna mungkin dalam keadaan belum login (harusnya dalam keadaan login)*/
/*F.S. Pengguna berhasil keluar */


#endif
