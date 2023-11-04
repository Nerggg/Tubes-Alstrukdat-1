#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "boolean.h"
#include "wordmachine.h"
#include "matrix.h"

typedef struct { 
	Word nama;
	Word pass;
	Word bio;
	Word hp;
	Word weton;
	Word jakun;
	Matrix PP;
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

void displayNama(Pengguna);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan nama pengguna */

void displayBioAkun(Pengguna P);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan bio pengguna */

void displayNoHP(Pengguna P);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan no hp pengguna */

void displayWeton(Pengguna P);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan weton pengguna */

void displayPP(Pengguna P);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan foto profil pengguna */

void displayProfil(Pengguna P);
/*I.S. Pengguna terdefinisi*/
/*F.S. Menampilkan profil pengguna */

void inputNama(Pengguna *P);
/*I.S. Nama pengguna mungkin belum terdefinisi*/
/*F.S. Nama pengguna terdefinisi */

void inputBioAkun(Pengguna *P);
/*I.S. Bio pengguna mungkin belum terdefinisi*/
/*F.S. Bio pengguna terdefinisi */

void inputNoHP(Pengguna *P);
/*I.S. No hp pengguna mungkin belum terdefinisi*/
/*F.S. No hp pengguna terdefinisi */

void inputWeton(Pengguna *P);
/*I.S. Weton pengguna mungkin belum terdefinisi*/
/*F.S. Weton pengguna terdefinisi */

void inputPP(Pengguna *P);
/*I.S. Foto profil pengguna mungkin belum terdefinisi*/
/*F.S. Foto profil pengguna terdefinisi */

int lengthChar(char a[]);
/*I.S. Array of char terdefinisi*/
/*F.S. Menghasilkan panjang array of char */

boolean cekKata(Word a,char b[]);
/*I.S. Sebuah word dan sebuah array of char terdefinisi*/
/*F.S. Jika sama menghasilkan true, jika tidak menghasilkan false */

boolean cekWeton(Word l);
/*I.S. Format weton mungkin salah*/
/*F.S. Jika format betul menghasilkan true, jika salah menghasilkan false */

boolean cekNoHp(Word l);
/*I.S. Format no hp mungkin salah*/
/*F.S. Jika format betul menghasilkan true, jika salah menghasilkan false  */

void gantiProfil(Pengguna *P);
/*I.S : Menerima input berupa profil yang ingin diganti*/
/*F.S : Profil berhasil diganti */

void ubahFotoProfil (Pengguna *P);
/*I.S : Menerima input berupa profil yang ingin diganti foto profilnya*/
/*F.S : Foto profil berhasil diganti */

void aturJenisAkun (Pengguna *P);
/*I.S : Menerima Profil yang memiliki jenis akun privat atau publik */
/*F.S : Jika jenis akun awalnya privat maka akan diubah ke publik begitu juga sebaliknya */

#endif
