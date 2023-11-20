#include <stdio.h>
#include "operational.h"

Word bacakalimat() { // untuk baca input dari user yang ada spasinya
	STARTSENTENCE();
	return currentWord;
}

Word baca() { // untuk baca input dari user yang satu kata doang
	STARTWORD();
	return currentWord;
}

boolean cek(Word kata, char target[]) { // untuk ngecek kesamaan antara word dengan array of char
	boolean sama = true;
	for (int i = 0; i < kata.Length; i++) {
		if (kata.TabWord[i] != target[i]) {
			sama = false;
			break;
		}		
	}	
	return sama;
}

int pindahfungsi(Word kata) { // untuk pindah2 fungsi dari sini
	if (cek(kata, "DAFTAR")) {
		return 1;
	}
	else if (cek(kata, "MASUK")) {
		return 2;
	}
	else if (cek(kata, "KELUAR")) {
		return 3;
	}
	else if (cek(kata, "TUTUP_PROGRAM")) {
		return 4;
	}
	else if (cek(kata, "GANTI_PROFIL")) {
		return 5;
	}	
	else if (cek(kata, "LIHAT_PROFIL")) {
		return 6;
	}	
	else if (cek(kata, "ATUR_JENIS_AKUN")) {
		return 7;
	}	
	else if (cek(kata, "UBAH_FOTO_PROFIL")) {
		return 8;
	}
	else if (cek(kata, "KICAU")) {
		return 9;
	}
	else if (cek(kata, "KICAUAN")) {
		return 10;
	}	
	else if (cek(kata, "SUKA_KICAUAN")) {
		return 11;
	}
	else if (cek(kata, "UTAS")) {
		return 12;
	}
	else if (cek(kata, "SAMBUNG_UTAS")) {
		return 13;
	}
	else if (cek(kata, "HAPUS_UTAS")) {
		return 14;
	}	
	else if (cek(kata, "CETAK_UTAS")) {
		return 15;
	}	
	else if (cek(kata, "DAFTAR_TEMAN")) {
		return 16;
	}
	else if (cek(kata, "HAPUS_TEMAN")) {
		return 17;
	}
	else if (cek(kata, "BALAS")) {
		return 18;
	}
	else if(cek(kata, "BALASAN")) {
		return 19;
	}
	else if(cek(kata, "HAPUS_BALASAN")) {
		return 20;
	}
	else if (cek(kata, "BUAT_DRAFT")) {
		return 21;
	}
	else if (cek (kata, "LIHAT_DRAFT")) {
		return 22;
	}
	else{
		return -1;
	}
}