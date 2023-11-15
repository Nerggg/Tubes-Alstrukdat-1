#include <stdio.h>
#include "misc.h"
#include "operational.h"

int wtoi(Word kata) { // convert word to integer
	int res = 0, temp;
	for (int i = 0; i < kata.Length; i++) {
		if (kata.TabWord[i] == '0') {
			temp = 0;
		}
		else if (kata.TabWord[i] == '1') {
			temp = 1;
		}
		else if (kata.TabWord[i] == '2') {
			temp = 2;
		}
		else if (kata.TabWord[i] == '3') {
			temp = 3;
		}
		else if (kata.TabWord[i] == '4') {
			temp = 4;
		}
		else if (kata.TabWord[i] == '5') {
			temp = 5;
		}
		else if (kata.TabWord[i] == '6') {
			temp = 6;
		}
		else if (kata.TabWord[i] == '7') {
			temp = 7;
		}
		else if (kata.TabWord[i] == '8') {
			temp = 8;
		}
		else if (kata.TabWord[i] == '9') {
			temp = 9;
		}
		res = res * 10 + temp;
	}
	return res;
}

int ctoi(char karakter) { // convert satu char to integer
	if (karakter == '0') {
		return 0;
	}
	else if (karakter == '1') {
		return 1;
	}
	else if (karakter == '2') {
		return 2;
	}
	else if (karakter == '3') {
		return 3;
	}
	else if (karakter == '4') {
		return 4;
	}
	else if (karakter == '5') {
		return 5;
	}
	else if (karakter == '6') {
		return 6;
	}
	else if (karakter == '7') {
		return 7;
	}
	else if (karakter == '8') {
		return 8;
	}
	else if (karakter == '9') {
		return 9;
	}
	else{
		return -1;
	}
}

Word ctow(char huruf[]) { // convert array of char ke word
	Word res;
	int i = 0;
	while (huruf[i] != '\0') {
		res.TabWord[i] = huruf[i];
		i++;
	}
	res.TabWord[i] = '\0';
	res.Length = i-1;
	return res;
}

Word concat(char awal[], char akhir[]) { // menggabungkan dua array of char dan mereturnnya sbg word
	Word res;
	int i = 0, j = 0;
	for (i = 0; awal[i] != '\0'; i++) {
		res.TabWord[i] = awal[i];
	}
	for (j = 0; akhir[j] != '\0'; j++) {
		res.TabWord[i+j] = akhir[j];
	}
	res.TabWord[i+j] = '\0';
	res.Length = i + j;
	return res;
}

boolean ceksama(Word kata1, Word kata2) { // cek kesamaan antara dua word
	if (kata1.Length != kata2.Length) {
		return false;
	}
	else {
		for (int i = 0; i < kata1.Length; i++) {
			if (kata1.TabWord[i] != kata2.TabWord[i]) {
				return false;
			}
		}
	}
	return true;
}

boolean belumlogin(Word currentUser) {
	if (cek(currentUser, ";;;")) {
		return true;
	}
	else {
		return false;
	}
}