#include <stdio.h>
#include <stdlib.h>
#include "feat/operational.c"

int main() {
	Word opt;
	boolean first = true;
	int move;
	while (true) {
		printf("masukkan perintah\n");
		opt = baca();
		move = pindahfungsi(opt);
		switch(move) {
			case 1:
				printf("daftar\n");
				break;
			case 2:
				printf("masuk\n");
				break;
			case 3:
				printf("keluar\n");
				break;
			case 4:
				printf("tutup program\n");
				break;
		}
	}
}
