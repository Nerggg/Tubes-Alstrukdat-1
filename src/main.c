#include <stdio.h>
#include "feat/operational.c"

int main() {
	Word tes;
	int move;
	printf("masukkan perintah\n");
	tes = baca();
	move = pindahfungsi(tes);
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
