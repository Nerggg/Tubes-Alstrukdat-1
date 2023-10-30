#include <stdio.h>

#include "feat/operational.c"
#include "feat/io.c"

#include "adt/pengguna.h"

int main() {
	Word opt, configfolder;
	UserDB user;
	int move;
	printf("masukkan nama folder\n");
	configfolder = baca();
	bacaconfig(&user, configfolder);
	printf("config berhasil dibuka!\n");
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
