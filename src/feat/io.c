#include "io.h"
#include "misc.h"
#include <stdio.h>

void penggunaconfig(UserDB *user, Graf *teman, Word namafolder) {
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
		user->db[i].nama = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].pass = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].bio = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].hp = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].weton = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
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

		int j, row, col;

		for (int a = 0; a < user->Neff; a++) {
			for (int b = 0; b < user->Neff; b++) {
				fgets(temp, sizeof(temp), fptr);
				j = 0;
				row = 0, col = 0;
				teman->mem[row][col] = wtoi(ctow(temp));
				j += 2;
				col++;
			}
			j = 0;
			col = 0;
			row++;
		}
	}
	fclose(fptr);
}

void utasconfig(ListUtas *utas, ListDinkicau l, Word namafolder) {
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
	utas->neff = n;
	while (n != 0) {
		fgets(temp, sizeof(temp), fptr); // ini mindahin kicauan ke utas utama
		utas->utasan[i].k.id = wtoi(ctow(temp));
		for (int j = 0; j < l.nEff; j++) {
			if (l.buffer[j].id == utas->utasan[i].k.id) {
				utas->utasan[i].k = l.buffer[j];
				break;
			}
		}

		Address p = utas->utasan[i].u;

		fgets(temp, sizeof(temp), fptr); // ini baca jlh utas yg ada
		int jlhutas = wtoi(ctow(temp));
		for (int j = 0; j < jlhutas; j++) {
			fgets(temp, sizeof(temp), fptr); // ini untuk baca isi utas
			p->isi = ctow(temp);
			fgets(temp, sizeof(temp), fptr); // ini skip line author
			fgets(temp, sizeof(temp), fptr); // ini utk baca date
			p->date = ctow(temp);
			p = p->next;
		}

		i++;
		n--;
	}	
}

void kicauanconfig(ListDinkicau *l, Word namafolder) {
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
	l->nEff = n;
	while (n != 0) {
		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].id = wtoi(ctow(temp));

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].text = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].like = wtoi(ctow(temp));

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].author = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].date = ctow(temp);

		i++;
		n--;
	}		
}


void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	penggunaconfig(user, teman, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	utasconfig(utas, *l, namafolder);
	kicauanconfig(l, namafolder);
}
