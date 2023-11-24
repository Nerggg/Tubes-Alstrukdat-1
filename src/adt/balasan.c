/* File : tree.h */
/* ADT pohon N-Ary */
/* Representasi Address dengan pointer */

#include "balasan.h"

AddressBalasan NewTreeNodeBalasan(InfotypeBalasan root)
/* Mengalokasikan sebuah Address t, bernilai Nil jika tidak berhasil */
/* Mengirimkan Address hasil alokasi sebuah elemen bernilai root
   Jika alokasi berhasil, maka Address tidak Nil dan menghasilkan t
   ROOT(t) = val, SUBADDRESS(t) terdefinisi dengan ukuran INITIAL,
   TREECOUNT(t) = 0, dan TREECAPACITY(t) = INITIAL 
   Jika alokasi gagal, maka mengirimkan Nil */
{
	AddressBalasan t = (AddressBalasan) malloc(sizeof(NodeBalasan));

	if (t != Nil_BALASAN) 
	{
		ROOT_BALASAN(t) = root;
		SUBADDRESS_BALASAN(t) = (AddressBalasan*) malloc(INITIAL_BALASAN * sizeof(AddressBalasan*));
		TREECOUNT_BALASAN(t) = 0;
		TREECAPACITY_BALASAN(t) = INITIAL_BALASAN;
	}

	return t;
}

TreeBalasan NewTreeBalasan(InfotypeBalasan root, TreeBalasan child)
/* Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   dan TREECOUNT bertambah satu jika child bukan Nil */
/* Jika alokasi gagal, menghasilkan pohon kosong (Nil) */
{
	AddressBalasan t = NewTreeNodeBalasan(root);
	if (t != Nil_BALASAN)
	{
		SUBTREE_BALASAN(t, TREECOUNT_BALASAN(t)) = child;

		if (child != Nil_BALASAN)
			TREECOUNT_BALASAN(t)++;
	}
	return t;
}

void CreateTreeBalasan(InfotypeBalasan root, TreeBalasan child, TreeBalasan *t)
/* I.S. : Sembarang
   F.S. : Menghasilkan sebuah pohon t
   		  Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   		  dan TREECOUNT bertambah satu jika child bukan Nil
   		  Jika alokasi gagal, menghasilkan pohon kosong (Nil) */
{
	*t = NewTreeNodeBalasan(root);
	if (*t != Nil_BALASAN)
	{
		SUBTREE_BALASAN(*t, TREECOUNT_BALASAN(*t)) = child;

		if (child != Nil_BALASAN)
			TREECOUNT_BALASAN(*t)++;
	}
}

void ConnectChildBalasan(TreeBalasan child, TreeBalasan *t)
/* I.S. : t dan child terdefinisi
   F.S. : t terhubung dengan child dan TREECOUNT bertambah satu jika child bukan Nil */
{
	if (TREECOUNT_BALASAN(*t) == TREECAPACITY_BALASAN(*t))
		ExpandCapacityBalasan(t);

	SUBTREE_BALASAN(*t, TREECOUNT_BALASAN(*t)) = child;

	if (child != Nil_BALASAN)
		TREECOUNT_BALASAN(*t)++;
}

void ConnectParentBalasan(TreeBalasan parent, TreeBalasan *t)
/* I.S. : t dan parent terdefinisi
	F.S. : t menjadi child dari parent, ROOT(t) menjadi ROOT(parent) */
{
	ConnectChildBalasan(*t, &parent);

	*t = parent;
}

void DeallocateTreeBalasan(AddressBalasan t)
/* I.S. : t terdefinisi
   F.S. : t dikembalikan ke sistem
   Melakukan dealokasi/pengembalian Address t */
{
	free(t);
}

boolean HasNoChildBalasan(TreeBalasan t)
/* Mengirimkan true jika t tidak memiliki child */
{
	if (TREECOUNT_BALASAN(t) == 0)
		return true;
	return false;
}

boolean HasOneChildBalasan(TreeBalasan t)
/* Mengirimkan true jika t hanya memiliki 1 child */
{
	if (TREECOUNT_BALASAN(t) == 1)
		return true;
	return false;
}

/***** Display Tree *****/
// void PrintTreeBalasan(TreeBalasan t)
// /* I.S. : t terdefinisi
//    F.S. : Semua simpul t sudah dicetak secara preorder: root dan child(ren)
//    		  Setiap pohon ditandai dengan tanda kurung buka dan tanda kurung tutup ()
//    		  Pohon kosong ditandai dengan () */
// {
// 	if (t == Nil_BALASAN) {
// 		// printf("()");
// 	} else {
// 		printf("(");
// 		printf("%d", ROOT_BALASAN(t));
// 		int i;
// 		for (i = 0; i < TREECOUNT_BALASAN(t); i++)
// 			PrintTreeBalasan(SUBTREE_BALASAN(t,i));
// 		printf(")");
// 	}
// }

void ExpandCapacityBalasan(TreeBalasan *t)
/* Proses: Memperbesar dua kali lipat capacity t */
/* I.S. : t terdefinisi */
/* F.S. : Ukuran SubTree menjadi dua kali lipat ukuran semula */
{
	TREECAPACITY_BALASAN(*t) *= 2;

	AddressBalasan *temp = SUBADDRESS_BALASAN(*t);

	SUBADDRESS_BALASAN(*t) = (AddressBalasan*) malloc(TREECAPACITY_BALASAN(*t) * sizeof(AddressBalasan*));
	TREECOUNT_BALASAN(*t) = 0;
	
	int i;
	for (i = 0; i < TREECAPACITY_BALASAN(*temp); i++)
		SUBTREE_BALASAN(*t,i) = SUBTREE_BALASAN(*temp,i);
}

void insertTreeBalasan(TreeBalasan t, int parentID, InfotypeBalasan child) {
	boolean found = false;
	TreeBalasan c = NewTreeBalasan(child, Nil_BALASAN);

	insertTreeRecursionBalasan(t, parentID, c, &found);
}

void insertTreeRecursionBalasan(TreeBalasan t, int parentID, TreeBalasan child, boolean* f) {
	if (t != Nil_BALASAN) {
		int i = 0;

		if (ROOT_BALASAN(t).id == parentID) {
			*f = true;
			ConnectChildBalasan(child, &t);
		}
			// if (operation == 'd') printf("(%d: %d)", ROOT(t), *f);

		while (i < TREECOUNT_BALASAN(t) && !(*f)) {
			insertTreeRecursionBalasan(SUBTREE_BALASAN(t, i), parentID, child, f);
			i += 1;
		}
	}
}

void deleteTreeBalasan(TreeBalasan* t, int parentID) {
	boolean found = false;

	deleteTreeRecursionBalasan(t, parentID, &found);
}

void deleteTreeRecursionBalasan(TreeBalasan* t, int parentID, boolean* f) {
	if (*t != Nil_BALASAN) {
		int i = 0;

		if (ROOT_BALASAN(*t).id == parentID) {
			*f = true;
			*t = Nil_BALASAN;
		}

		while (!(*f) && i < TREECOUNT_BALASAN(*t)) {
			deleteTreeRecursionBalasan(&SUBTREE_BALASAN(*t, i), parentID, f);
			i += 1;
		}
	}
}

boolean treeExists(TreeBalasan t, int parentID) {
	boolean found = false;

	searchTreeRecursion(t, parentID, &found);
	return found;
}

void searchTreeRecursion(TreeBalasan t, int parentID, boolean *f) {
	if (t != Nil_BALASAN) {
		int i = 0;

		if (ROOT_BALASAN(t).id == parentID) {
			*f = true;
		}

		while (!(*f) && i < TREECOUNT_BALASAN(t)) {
			searchTreeRecursion(SUBTREE_BALASAN(t, i), parentID, f);
			i += 1;
		}
	}
}

void cetakIndent(int indent) {
	for (int i = 0; i < indent; i++) {
		printf("\t");
	}
}

void cetakBalasan(Word currentUser, AddressBalasan balasan, UserDB user, Graf teman, int depth) {	
	if (balasan == NULL) {
		return;
	}

	int i = 0;

	Pengguna currentPengguna;
	for (int a = 0; a < user.Neff; a++) {
		if (ceksama(currentUser, user.db[a].nama)) {
			currentPengguna = user.db[a];
			break;
		}
	}

	if (ROOT_BALASAN(balasan).id != -1) {

		Pengguna pembalas;
		for (int a = 0; a < user.Neff; a++) {
			if (ceksama(balasan->T.author, user.db[a].nama)) {
				pembalas = user.db[a];
				break;
			}
		}

		boolean berteman = false;
		if (cekteman(currentPengguna, pembalas, &user, teman)) {
    	    berteman = true;
    	}

		if (cek(pembalas.jakun, "Publik") || ((cek(pembalas.jakun, "Privat") && berteman))) {
			cetakIndent(depth);	
			printf("| ID = %d\n", balasan->T.id);
			cetakIndent(depth);
			printf("| ");
			PrintWord(balasan->T.author);
			printf("\n");
			cetakIndent(depth);
			printf("| ");
			PrintWord(balasan->T.date);
			printf("\n");
			cetakIndent(depth);
			printf("| ");
			PrintWord(balasan->T.text);
			printf("\n");
		}
		else {
			cetakIndent(depth);	
			printf("| ID = %d\n", balasan->T.id);
			cetakIndent(depth);
			printf("| PRIVAT\n");
			cetakIndent(depth);
			printf("| PRIVAT\n");
			cetakIndent(depth);
			printf("| PRIVAT\n");	
		}
	
	}

	while (i < TREECOUNT_BALASAN(balasan)) {	
		cetakBalasan(currentUser, SUBTREE_BALASAN(balasan, i), user, teman, depth+1);
		i += 1;
	}
}

void buatBalasan(Word currentUser, ListDinkicau kicauan, ListTreeBalasan *balasan, UserDB user, Graf teman, int idkicau, int idbalas) {
	if (cek(currentUser, ";;;")) {
		printf("Anda belum login! Silahkan login terlebih dahulu untuk menikmati layanan BurBir.\n");
		return;
	}

	boolean adakicau = false;
	int idxkicau;
	for (idxkicau = 0; idxkicau < kicauan.nEff; idxkicau++) {
		if (kicauan.buffer[idxkicau].id == idkicau) {
			adakicau = true;
			break;
		}
	}

	if (!adakicau) {
		printf("Tidak ada kicauan dengan id berikut\n");
		return;
	}

	Pengguna currentPengguna;
	Pengguna pembuatKicau;
	for (int a = 0; a < user.Neff; a++) {
		if (ceksama(currentUser, user.db[a].nama)) {
			currentPengguna = user.db[a];
			break;
		}
	}

	for (int a = 0; a < kicauan.nEff; a++) {
		if (kicauan.buffer[a].id == idkicau) {
			for (int b = 0; b < user.Neff; b++) {
				if (ceksama(kicauan.buffer[a].author, user.db[b].nama)) {
					pembuatKicau = user.db[b];
					break;
				}
			}
		}
	} 

	boolean berteman = false;
	if (cekteman(currentPengguna, pembuatKicau, &user, teman)) {
		berteman = true;
	}

	if (cek(pembuatKicau.jakun, "Privat") && !berteman) {
		printf("Kicauan tersebut tidak bisa dibalas karena dibuat oleh akun privat.\n");
		return;
	}

	boolean adabalas = false;
	int idxbalasan;
	for (int a = 0; a < balasan->neff; a++) {
		if (balasan->isi[a]->IDParent == idkicau) {
			adabalas = true;
			idxbalasan = a;
			// printf("\n\n\nadamasuk kesini\n\n\n");
			// printf("idx balasannya %d\n", idxbalasan);
			break;
		}
	}

	AddressBalasan parent;

	if (!adabalas) {
		balasan->isi[balasan->neff] = malloc(sizeof(NodeBalasan));
		idxbalasan = balasan->neff;
		// printf("yg pertama dia %d\n", idxbalasan);
		Balasan tempParent;

		for (int a = 0; a < kicauan.nEff; a++) {
			if (kicauan.buffer[idxkicau].id == idkicau) {
				tempParent.id = idkicau;
				tempParent.text = kicauan.buffer[idxkicau].text;
				tempParent.author = kicauan.buffer[idxkicau].author;
				tempParent.date = kicauan.buffer[idxkicau].date;
				break;
			}
		}

		parent = NewTreeNodeBalasan(tempParent);
		parent->IDParent = idkicau;
		balasan->neff++;
	}
	else {
		parent = balasan->isi[idxbalasan];
	}

	if (idbalas != -1) {
		if (!treeExists(parent, idbalas)) {
			printf("Kicauan tersebut tidak memiliki balasan dengan id %d.\n", idbalas);
			return;
		}
	}

	Balasan tempBalasan;
	tempBalasan.author = currentUser;
	tempBalasan.date = ctow(DateTimeToString(CurrentDatetime()));
	if (adabalas) {
		tempBalasan.id = parent->Count+1;
	}
	else {
		// printf("dia kebawah\n");
		tempBalasan.id = 1;
	}
	printf("Masukkan balasan:\n");
	Word text = bacakalimat();
	tempBalasan.text = text;

	printf("Selamat! Balasan telah diterbitkan!\n");
	printf("Detik balasan: \n");
	printf("| ID = %d\n", tempBalasan.id);
	printf("| ");
	PrintWord(tempBalasan.author);
	printf("\n");
	printf("| ");
	PrintWord(tempBalasan.date);
	printf("\n");
	printf("| ");
	PrintWord(tempBalasan.text);
	printf("\n");

	AddressBalasan p = NewTreeNodeBalasan(tempBalasan);
	if (idbalas == -1) {
		ConnectParentBalasan(parent, &p);
		// printf("hasilnya\n");
		// printf("%s\n", parent->T.text.TabWord);
	}
	else {
		// printf("ini kbeawah\n");
		// parent->Count++;
		insertTreeBalasan(parent, idbalas, tempBalasan);
	}

	
	balasan->isi[idxbalasan] = parent;
}