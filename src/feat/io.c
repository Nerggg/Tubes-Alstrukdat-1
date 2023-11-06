#include "misc.c"
#include "../adt/pengguna.h"
#include "../adt/matrix.c"

void penggunaconfig(UserDB *user, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[50];
	char awal[] = "../cfg/";
	char akhir[] = "/pengguna.config";
	Word location = concat(awal, namafolder.TabWord);
	location = concat(location.TabWord, akhir);
	fptr = fopen(location.TabWord, "r");
	fgets(temp, sizeof(temp), fptr);
	int n = wtoi(ctow(temp));
	user->Neff = n;
	while (n != 0) {
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].nama = ctow(temp);
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].pass = ctow(temp);
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].bio = ctow(temp);
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].hp = ctow(temp);
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].weton = ctow(temp);
		fgets(temp, sizeof(temp), fptr);
		while (temp[0] == '\n') {
			fgets(temp, sizeof(temp), fptr);
		}
		user->db[i].jakun = ctow(temp);

		for (int a = 0; a < 5; a++) {
			fgets(temp, sizeof(temp), fptr);
			while (temp[0] == '\n') {
				fgets(temp, sizeof(temp), fptr);
			}
			for (int b = 0; b < 10; b++) {
				user-> db[i].PP.mem[a][b] = temp[b];
			}
		}
		n--;
		i++;
	}
	fclose(fptr);
}

void bacaconfig(UserDB *user, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	penggunaconfig(user, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
}
