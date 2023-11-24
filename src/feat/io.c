#include "io.h"
#include "misc.h"
#include "../adt/kicauan.h"
#include <stdio.h>
#include <stdlib.h>

void penggunaconfig(UserDB *user, Graf *pertemanan, prioqueuefren *permintaanTeman, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[280];
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
				pertemanan->mem[a][b] = ctoi(temp[idx]);
				idx++;
			}
		}
	}

	fgets(temp, sizeof(temp), fptr);
	int jlhPermintaanTeman = wtoi(ctow(temp));
	DeAlokasiprio(permintaanTeman);
	MakeEmptyprio(permintaanTeman, jlhPermintaanTeman);

	char *tempAngka = malloc(sizeof(char) * 2);
	for (int a = 0; a < jlhPermintaanTeman; a++) {
		teman tempTeman;
		free(tempAngka);
		tempAngka = malloc(sizeof(char) * 2);
		int pjgAngka = 0;
		int b = 0;
		int indicator = 0; // utk nentuin masukin angkanya kemana
		fgets(temp, sizeof(temp), fptr);
		while (temp[b] != '\n') {
			if (temp[b] == ' ') {
				tempAngka[pjgAngka+1] = '\0';
				// printf("temp angkanya %s\n", tempAngka);
				pjgAngka = 0;
				if (indicator == 0) {
					tempTeman.IDpengirim = wtoi(ctow(tempAngka));
					indicator = 1;
				}
				else if (indicator == 1) {
					tempTeman.IDpenerima = wtoi(ctow(tempAngka));
				}
				free(tempAngka);
				tempAngka = malloc(sizeof(char) * 2);
			}
			else {
				tempAngka[pjgAngka] = temp[b];
				pjgAngka++;
			}
			b++;
		}
		tempAngka[pjgAngka+1] = '\0';
		// printf("temp angkanya %s\n", tempAngka);
		tempTeman.Jumlahteman = wtoi(ctow(tempAngka));
		Enqueueprio(permintaanTeman, tempTeman);
		// printf("ini hasilnya\n");
		// PrintPrioQueue(*permintaanTeman, *user);
	}

	fclose(fptr);
}

void utasconfig(ListUtas *utas, ListDinkicau l, Word namafolder) {
	FILE *fptr;
	int i = 0;
	char temp[280];
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
	char temp[280];
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
void balasanconfig(UserDB user, ListDinkicau kicauan, ListTreeBalasan *balasan, Word namafolder)
{
	FILE *fptr;
	char temp[280];
	char akhir[] = "/balasan.config";
	Word location = concat(namafolder.TabWord, akhir);
	// printf("%s\n", location.TabWord);
	fptr = fopen(location.TabWord, "r");
	fgets(temp, sizeof(temp), fptr); 

	int n = wtoi(ctow(temp));
	balasan->neff = n;
	balasan->isi = malloc(sizeof(NodeBalasan)*n);
	for (int i = 0; i < n; i++) {
		Balasan tempParent;
		fgets(temp, sizeof(temp), fptr);
		int idkicau = wtoi(ctow(temp));

		for (int a = 0; a < kicauan.nEff; a++) {
			if (kicauan.buffer[i].id == idkicau) {
				tempParent.id = idkicau;
				tempParent.text = kicauan.buffer[i].text;
				tempParent.author = kicauan.buffer[i].author;
				tempParent.date = kicauan.buffer[i].date;
				break;
			}
		}

		AddressBalasan parent = NewTreeNodeBalasan(tempParent);
		parent->IDParent = idkicau;

		fgets(temp, sizeof(temp), fptr);
		int jlhbalasan = wtoi(ctow(temp));

		int idxparent, idxself;

		char *tempAngka = malloc(sizeof(char)*2);
		for (int a = 0; a < jlhbalasan; a++) {
			free(tempAngka);
			tempAngka = malloc(sizeof(char)*2);
			int pjgAngka = 0;
			int b = 0;

			fgets(temp, sizeof(temp), fptr);
			while(temp[b] != '\n') {
				if (temp[b] == ' ') {
					tempAngka[pjgAngka+1] = '\0';
					// printf("tempangka parent %s\n", tempAngka);
					pjgAngka = 0;
					idxparent = wtoi(ctow(tempAngka));
					// printf("parent setelah diconvert %d\n", idxparent);
					free(tempAngka);
					tempAngka = malloc(sizeof(char)*2);
				}
				else {
					tempAngka[pjgAngka] = temp[b];
					pjgAngka++;
				}
				b++;
			}
			tempAngka[pjgAngka+1] = '\0';
			// printf("tempangka self %s\n", tempAngka);
			idxself = wtoi(ctow(tempAngka));
			// printf("self setelah diconvert %d\n", idxself);

			Balasan tempBalasan;
			tempBalasan.id = idxself;
			fgets(temp, sizeof(temp), fptr);
			tempBalasan.text = ctow(temp);
			fgets(temp, sizeof(temp), fptr);
			tempBalasan.author = ctow(temp);
			fgets(temp, sizeof(temp), fptr);
			tempBalasan.date = ctow(temp);

			AddressBalasan q = NewTreeNodeBalasan(tempBalasan);

			// printf("idxparentnya %d dan selfnya %d\n", idxparent, idxself);
			if (idxparent == -1) {
				// printf("isinya %s\n", q->T.text.TabWord);
				ConnectParentBalasan(parent, &q);
			}
			else {
				// printf("isinya %s\n", q->T.text.TabWord);
				insertTreeBalasan(parent, idxparent, tempBalasan);
			}
		}

		balasan->isi[i] = parent;
	}
}

void draftconfig(UserDB user, ListStack *sl, Word namafolder)
{
	FILE *fptr;
	int i = 0;
	char temp[280];
	char akhir[] = "/draf.config";
	Word location = concat(namafolder.TabWord, akhir);
	fptr = fopen(location.TabWord, "r");	
	fgets(temp, sizeof(temp), fptr); // banyak stack
	int n = wtoi(ctow(temp));
	sl->nEff = n;
	while (n != 0){
		CreateEmptyStack(&sl->buffer[i]);
		int j = 0;
		char tempnama[30];
		fgets(temp, sizeof(temp), fptr);
		while (temp[j] != '0' && temp[j] != '1' && temp[j] != '2' && temp[j] != '3' && temp[j] != '4' && temp[j] != '5' && temp[j] != '6' && temp[j] != '7' && temp[j] != '8' && temp[j] != '9') {
			// printf("isi temp nya %c\n", temp[j]);
			tempnama[j] = temp[j];
			j++;
		}
		// printf("tempnama j nya %c\n", tempnama[j]);
		// printf("tempnamanya %s\n", tempnama);
		tempnama[j] = '\0';
		sl->buffer[i].author = ctow(tempnama);

		char tempangka[30];
		int jj = 0;
		while (temp[jj+j] != '\n') {
			tempangka[jj] = temp[jj+j];
			jj++;
		}
		// printf("tempangkanya %s\n", tempangka);
		tempangka[jj] = '\0';
		Word tempAngkaWord = ctow(tempangka);
		tempAngkaWord.Length++;
		// printf("setelah di convert jadi %s\n", ctow(tempangka).TabWord);
		int jlhdraf = wtoi(tempAngkaWord);
		// printf("temp angkanya %d\n", jlhdraf);
		// printf("\n");

		Stack tempStack;
		for (int a = 0; a < jlhdraf; a++) {
			CreateEmptyStack(&tempStack);
			Kicau tempKicauan;
			tempKicauan.author = sl->buffer[i].author;
			tempKicauan.id = jlhdraf-a;
			tempKicauan.like = 0;
			fgets(temp, sizeof(temp), fptr);
			tempKicauan.text = ctow(temp);
			fgets(temp, sizeof(temp), fptr);
			tempKicauan.date = ctow(temp);

			// printf("datenya %s", tempKicauan.date.TabWord);

			for (int b = 0; b < user.Neff; b++) {
				if (ceksama(user.db[b].nama, tempKicauan.author)) {
					tempKicauan.jakunkicau = user.db[b].jakun;
					break;
				}
			}
			
			sl->buffer[i].T[jlhdraf-a-1] = tempKicauan;
		}
		sl->buffer[i].Nstack = jlhdraf;
		sl->buffer[i].TOP = jlhdraf-1;

		// Kicau tempTempKicauan;
		// while (!IsEmptyStack(tempStack)) {
		// 	printf("masuk\n");
		// 	PopKicau(&tempStack, &tempTempKicauan);
		// 	PushKicau(&(sl->buffer[i]), tempTempKicauan);
		// }

		i++;
		n--;
	}
}

void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, prioqueuefren *permintaanTeman, ListTreeBalasan *balasan, ListStack *sl, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	char awal[] = "../cfg/";
	namafolder = concat(awal, namafolder.TabWord);
	penggunaconfig(user, teman, permintaanTeman, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	// printf("1 aman\n");
	kicauanconfig(*user, l, namafolder);	
	// printf("2 aman\n");	
	utasconfig(utas, *l, namafolder);
	// printf("3 aman\n");
	draftconfig(*user, sl, namafolder);
	balasanconfig(*user, *l, balasan, namafolder);
	// printf("4 aman\n");
	// draftconfig(*user, sl, namafolder);	
}

void driverbacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, prioqueuefren *permintaanTeman, ListTreeBalasan *balasan, ListStack *sl, Word namafolder) { // nanti disini tambahin parameter bertipe adt buatan untuk nampung datanya
	char awal[] = "../../cfg/";
	namafolder = concat(awal, namafolder.TabWord);
	penggunaconfig(user, teman, permintaanTeman, namafolder); // dan disini tambahin fungsi baca confignya, sesuain ama format yg di spek
	// printf("1 aman\n");
	kicauanconfig(*user, l, namafolder);	
	// printf("2 aman\n");	
	utasconfig(utas, *l, namafolder);
	// printf("3 aman\n");
	balasanconfig(*user, *l, balasan, namafolder);
	
	draftconfig(*user, sl, namafolder);
}
