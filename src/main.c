#include <stdio.h>
#include "adt/pengguna.c"

int main() {
	Word opt, configfolder, currentUser;
	UserDB user;
	int move;	
	printf("masukkan nama folder\n");
	configfolder = baca();
	bacaconfig(&user, configfolder);
	printf("config berhasil dibuka!\n");
	emptyuser(&currentUser);
	while (true) {
		printf("masukkan perintah\n");
		opt = baca();
		move = pindahfungsi(opt);
		switch(move) {
			case 1:
				daftar(&user, &currentUser);
				break;
			case 2:
				masuk(&user, &currentUser);
				break;
			case 3:
				keluar(&currentUser);
				break;
			case 4:
				printf("tutup program\n");
				break;
		}
	}
}
