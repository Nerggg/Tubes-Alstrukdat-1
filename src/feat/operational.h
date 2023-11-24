#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "../adt/wordmachine.h"
#include "../adt/charmachine.h"

Word bacakalimat(); // untuk baca input dari user yang ada spasinya
Word baca(); // untuk baca input dari user yang satu kata doang
boolean cek(Word kata, char target[]); // untuk ngecek kesamaan antara word dengan array of char
boolean cekCommand(Word kata, char target[], int length);
int pindahfungsi(Word kata); // untuk pindah2 fungsi dari sini

#endif
