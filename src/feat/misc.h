#ifndef MISC_H
#define MISC_H

#include "../adt/wordmachine.h"

int wtoi(Word kata); // convert word to integer
Word ctow(char huruf[]); // convert array of char ke word
Word concat(char awal[], char akhir[]); // menggabungkan dua array of char dan mereturnnya sbg word
boolean ceksama(Word kata1, Word kata2); // cek kesamaan antara dua word

#endif
