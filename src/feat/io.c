#include "io.h"
#include "misc.h"
#include "../adt/kicauan.h"
#include <stdio.h>
#include <stdlib.h>

void penggunaconfig(UserDB *user, Graf *teman, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[50];
	char akhir[] = "/pengguna.config";
	Word location = concat(namafolder.TabWord, akhir);
	fptr = fopen(location.TabWord, "r");
	fgets(temp, sizeof(temp), fptr);
	int n = wtoi(ctow(temp));
	user->Neff = n;
	while (n != 0) {
		fgets(temp, sizeof(temp), fptr);
		user->db[i].nama = ctow(temp);
		// printf("1: %s\n", ctow(temp).TabWord);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].pass = ctow(temp);
		// printf("2: %s\n", ctow(temp).TabWord);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].bio = ctow(temp);
		// printf("3: %s\n", ctow(temp).TabWord);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].hp = ctow(temp);
		// printf("4: %s\n", ctow(temp).TabWord);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].weton = ctow(temp);
		// printf("5: %s\n", ctow(temp).TabWord);

		fgets(temp, sizeof(temp), fptr);
		user->db[i].jakun = ctow(temp);
		// printf("6: %s\n", ctow(temp).TabWord);

		for (int a = 0; a < 5; a++) {
			int idx = 0;
			fgets(temp, sizeof(temp), fptr);
			// printf("%s\n", temp);
			for (int b = 0; b < 10; b++) {
				if (temp[idx] == ' ') {
					idx++;
					b--;
				}
				else {
					user->db[i].PP.mem[a][b] = temp[idx];
					// printf("isi b nya %c\n", temp[idx]);
					idx++;
				}
			}
		}
		n--;
		i++;

	}

	for (int a = 0; a < user->Neff; a++) {
		int idx = 0;
		fgets(temp, sizeof(temp), fptr);
		for (int b = 0; b < user->Neff; b++) {
			if (temp[idx] == ' ') {
				idx++;
				b--;
			}
			else {
				teman->mem[a][b] = ctoi(temp[idx]);
				idx++;
			}
		}
	}

	fclose(fptr);
}

void utasconfig(ListUtas *utas, ListDinkicau l, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[50];
	char akhir[] = "/utas.config";
	Word location = concat(namafolder.TabWord, akhir);
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

		utas->utasan[i].u = (Address)malloc(sizeof(Utas));
		Address p = utas->utasan[i].u;

		fgets(temp, sizeof(temp), fptr); // ini baca jlh utas yg ada
		int jlhutas = wtoi(ctow(temp));
		for (int j = 0; j < jlhutas; j++) {
			fgets(temp, sizeof(temp), fptr); // ini untuk baca isi utas
			// printf("stringnya %s\n", temp);
			p->isi = ctow(temp);
			fgets(temp, sizeof(temp), fptr); // ini skip line author
			fgets(temp, sizeof(temp), fptr); // ini utk baca date
			p->date = ctow(temp);

			if (j < jlhutas-1) {
				p->next = (Address)malloc(sizeof(Utas));
				p = p->next;
			}
			else {
				p->next = NULL;
			}
		}

		i++;
		n--;
	}	
	// for (int k = 0; k < utas->neff-1; k++) {
	// 	Address q = utas->utasan[k].u;
	// 	Address r = utas->utasan[k+1].u;
	// 	q->next = r;
	// 	r->next = NULL;
	// }
}

void kicauanconfig(UserDB user, ListDinkicau *l, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[50];
	char akhir[] = "/kicauan.config";
	Word location = concat(namafolder.TabWord, akhir);
	fptr = fopen(location.TabWord, "r");	
	fgets(temp, sizeof(temp), fptr);
	int n = wtoi(ctow(temp));
	if (n > l->capacity) {
		dealocateListkicau(l);
		CreateListDinkicau(l, n);
	}
	while (n != 0) {
		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].id = wtoi(ctow(temp));

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].text = ctow(temp);

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].like = wtoi(ctow(temp));

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].author = ctow(temp);

		Pengguna pengkicau = cariuser(user, l->buffer[i].author);
		l->buffer[i].jakunkicau = pengkicau.jakun;

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].date = ctow(temp);
		i++;
		n--;
		l->nEff++;
	}		
}


void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	char awal[] = "../cfg/";
	namafolder = concat(awal, namafolder.TabWord);
	penggunaconfig(user, teman, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	// printf("1 aman\n");
	kicauanconfig(*user, l, namafolder);	
	// printf("2 aman\n");	
	utasconfig(utas, *l, namafolder);
	// printf("3 aman\n");
}

void driverbacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	char awal[] = "../../cfg/";
	namafolder = concat(awal, namafolder.TabWord);
	penggunaconfig(user, teman, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	// printf("1 aman\n");
	kicauanconfig(*user, l, namafolder);	
	// printf("2 aman\n");	
	utasconfig(utas, *l, namafolder);
	// printf("3 aman\n");
}
