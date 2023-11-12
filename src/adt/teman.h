#ifndef TEMAN_H
#define TEMAN_H

#include "boolean.h"
#include "wordmachine.h"
#include "graph.h"
#include "pengguna.h"

void daftarteman(boolean login, Pengguna akun, UserDB* listAkun, Graf teman);
/* I.S. Pengguna mungkin belum memiliki teman dan belum melakukan login */
/* I.S. Apabila pengguna memiliki teman, program akan menampilkan daftar teman dari pengguna */

void hapusteman(boolean login, Pengguna akun, UserDB* listAkun, Graf* teman);
/* I.S. Pengguna mungkin belum berteman dengan teman yang ingin dihapus dan belum melakukan login */
/* F.S. Apabila pengguna sudah berteman, teman yang dihapus tidak lagi menjadi teman pengguna */
boolean cekteman(Pengguna akun, Pengguna cekakun, UserDB *listAkun, Graf teman);

#endif