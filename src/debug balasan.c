#include <stdio.h>
#include <stdlib.h>
#include "adt/pengguna.h"
#include "feat/io.h"
#include "feat/operational.h"
#include "adt/kicauan.h"
#include "adt/teman.h"
#include "adt/utas.h"
#include "adt/balasan.h"

int main() {
	Word configfolder, currentUser = {"Tuan Bri", 8};
	UserDB user;
	ListUtas utas;
	ListDinkicau kicauan;
	Graf teman;
	ListDintree ltree;
	// int move;	
	FILE *fptr;
	// int idkicau, indexParam;
	ListStack sl;

	CreateListDinkicau(&kicauan, 1);
	CreateListoftree(&ltree, 1);
	// CreateListDinStack(&sl, 20);

	printlogo();
	printf("\nSelamat datang di BurBir!\n");
	printf("Silahkan masukkan nama folder konfigurasi: ");
	configfolder = baca();
	Word location = concat("../cfg/", configfolder.TabWord);
	fptr = fopen(location.TabWord, "r");
	if (fptr == NULL) {
		printf("\nYah folder konfigurasi tidak ditemukan :(\n");
		return 0;
	}
	fclose(fptr);
	bacaconfig(&user, &utas, &kicauan, &teman ,&ltree , &sl, configfolder);
	printf("\nFile konfigurasi berhasil dimuat! Selamat menggunakan aplikasi BurBir!\n");
	printf("Ketik \';\' untuk melanjutkan\n\n");
	bacakalimat();

	// emptyuser(&currentUser);
    // masuk(&user, &currentUser);

    Balasan(user, currentUser, kicauan, ltree, teman, 2);
	printf("nefnya %d\n", ltree.nEff);
}