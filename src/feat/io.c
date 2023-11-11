#include "misc.c"
#include "../adt/pengguna.h"
#include "../adt/utas.h"
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
	DATETIME tempdatetime;
	int tempint;
	char temp[50];
	char awal[] = "../cfg/";
	char akhir[] = "/kicauan.config";
	Word location = concat(awal, namafolder.TabWord);
	location = concat(location.TabWord, akhir);
	fptr = fopen(location.TabWord, "r");
	fgets(temp, sizeof(temp), fptr);
	int n = wtoi(ctow(temp));
	l->nEff = n;
	while (n != 0) {
		char *temp = malloc(sizeof(char) * 50);
		fgets(temp, sizeof(temp), fptr);
		Word tempword = ctow(temp);
		l->buffer[i].author = tempword;

		fgets(temp, sizeof(tempdatetime), fptr);
		l->buffer[i].datetime = tempdatetime;

		fgets(temp, sizeof(tempint), fptr);
		l->buffer[i].id=tempint;

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].jakunkicau=tempword;

		fgets(temp, sizeof(tempint), fptr);
		l->buffer[i].like=tempint;

		fgets(temp, sizeof(temp), fptr);
		l->buffer[i].text=tempword;
		n--;
		i++;
	}
	fclose(fptr);
}


void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	penggunaconfig(user, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	utasconfig(utas, *l, namafolder);
	kicauanconfig(l,namafolder);
}
