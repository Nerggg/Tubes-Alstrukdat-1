#include <stdio.h>
#include <stdlib.h>
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
	FILE *fptr;
	CreateListDinkicau(&kicau, 1);

	system("clear");
	printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("| |   ______     | || | _____  _____ | || |  _______     | || |   ______     | || |     _____    | || |  _______     | |\n");
	printf("| |  |_   _ \\    | || ||_   _||_   _|| || | |_   __ \\    | || |  |_   _ \\    | || |    |_   _|   | || | |_   __ \\    | |\n");
	printf("| |    | |_) |   | || |  | |    | |  | || |   | |__) |   | || |    | |_) |   | || |      | |     | || |   | |__) |   | |\n");
	printf("| |    |  __'.   | || |  | '    ' |  | || |   |  __ /    | || |    |  __'.   | || |      | |     | || |   |  __ /    | |\n");
	printf("| |   _| |__) |  | || |   \\ `--' /   | || |  _| |  \\ \\_  | || |   _| |__) |  | || |     _| |_    | || |  _| |  \\ \\_  | |\n");
	printf("| |  |_______/   | || |    `.__.'    | || | |____| |___| | || |  |_______/   | || |    |_____|   | || | |____| |___| | |\n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");

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
	bacaconfig(&user, &utas, &kicau, &teman, configfolder);
	printf("\nFile konfigurasi berhasil dimuat! Selamat menggunakan aplikasi BurBir!\n");
	emptyuser(&currentUser);
	
	while (true) {
		printf(">> ");
		opt = baca();
		move = pindahfungsi(opt); // cek realisasi fungsinya di operational.c untuk tau kode angkanya
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
				printf("\nAnda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
				return 0;
			case 5:
				if (belumlogin(currentUser)) {
					printf("\nAnda belum login. Silahkan login terlebih dahulu untuk mengganti profil.\n");
					break;
				}
				for (int a = 0; a < user.Neff; a++) {
					if(ceksama(currentUser, user.db[a].nama)) {
						gantiProfil(&user.db[a]);
						break;
					}
				}
			case 6:
				Word nama;
				boolean flag = false;
				if (belumlogin(currentUser)) {
					printf("\nAnda belum login. Silahkan login terlebih dahulu untuk melihat profil.\n");
					break;
				}				
				nama = bacakalimat();
				for (int a = 0; a < user.Neff; a++) {
					if(ceksama(currentUser, user.db[a].nama)) {
						for (int b = 0; b < user.Neff; b++) {
							if(ceksama(nama, user.db[b].nama)) {
								LihatProfil(user.db[a], user.db[b], &user, &teman);
								flag = true;
								break;
							}
						}
					}
				}
				if (!flag) {
					printf("\nTidak ada akun dengan nama ");
					PrintWord(nama);
					printf(".\n");
					break;
				}
			case 7:
				if (belumlogin(currentUser)) {
					printf("\nAnda belum login. Silahkan login terlebih dahulu untuk mengatur jenis akun.\n");
					break;
				}
				for (int a = 0; a < user.Neff; a++) {
					if(ceksama(currentUser, user.db[a].nama)) {
						aturJenisAkun(&user.db[a]);
						break;
					}
				}			
			case 8:
				if (belumlogin(currentUser)) {
					printf("\nAnda belum login. Silahkan login terlebih dahulu untuk mengubah foto profil.\n");
					break;
				}
				for (int a = 0; a < user.Neff; a++) {
					if(ceksama(currentUser, user.db[a].nama)) {
						ubahFotoProfil(&user.db[a]);
						break;
					}
				}			
		}	
	}
}