#include <stdio.h>
#include "adt/pengguna.h"
#include "feat/io.h"
#include "feat/operational.h"
#include "adt/kicauan.h"
#include "adt/teman.h"
#include "adt/utas.h"

int main() {
	Word opt, configfolder, currentUser;
	UserDB user;
	ListUtas utas;
	ListDinkicau kicau;
	Graf teman;
	int move;	

	CreateListDinkicau(&kicau, 100);
	printf("masukkan nama folder\n");
	configfolder = baca();
	bacaconfig(&user, &utas, &kicau, &teman, configfolder);
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