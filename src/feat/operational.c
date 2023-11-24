#include <stdio.h>
#include "operational.h"

Word bacakalimat()
{ // untuk baca input dari user yang ada spasinya
	STARTSENTENCE();
	return currentWord;
}

Word baca()
{ // untuk baca input dari user yang satu kata doang
	STARTWORD();
	return currentWord;
}

boolean cek(Word kata, char target[])
{ // untuk ngecek kesamaan antara word dengan array of char
	boolean sama = true;
	for (int i = 0; i < kata.Length; i++)
	{
		if (kata.TabWord[i] != target[i])
		{
			sama = false;
			break;
		}
	}
	return sama;
}

boolean cekCommand(Word kata, char target[], int length)
{ // untuk ngecek kesamaan antara word dengan array of char
	boolean sama = true;
	if (kata.Length == length)
	{
		for (int i = 0; i < kata.Length; i++)
		{
			if (kata.TabWord[i] != target[i])
			{
				sama = false;
				break;
			}
		}
	}
	else
	{
		sama = false;
	}

	return sama;
}

int pindahfungsi(Word kata)
{ // untuk pindah2 fungsi dari sini
	if (cekCommand(kata, "SIMPAN", 7-1))
	{
		return 99;
	}
	else if (cekCommand(kata, "DAFTAR", 7-1))
	{
		return 1;
	}
	else if (cekCommand(kata, "MASUK", 6-1))
	{
		return 2;
	}
	else if (cekCommand(kata, "KELUAR", 7-1))
	{
		return 3;
	}
	else if (cekCommand(kata, "TUTUP_PROGRAM", 14-1))
	{
		return 4;
	}
	else if (cekCommand(kata, "GANTI_PROFIL", 13-1))
	{
		return 5;
	}
	else if (cekCommand(kata, "LIHAT_PROFIL", 13-1))
	{
		return 6;
	}
	else if (cekCommand(kata, "ATUR_JENIS_AKUN", 16-1))
	{
		return 7;
	}
	else if (cekCommand(kata, "UBAH_FOTO_PROFIL", 17-1))
	{
		return 8;
	}
	else if (cekCommand(kata, "KICAU", 6-1))
	{
		return 9;
	}
	else if (cekCommand(kata, "KICAUAN", 8-1))
	{
		return 10;
	}
	else if (cekCommand(kata, "SUKA_KICAUAN", 13-1))
	{
		return 11;
	}
	else if (cekCommand(kata, "UTAS", 15-1))
	{
		return 12;
	}
	else if (cekCommand(kata, "SAMBUNG_UTAS", 13-1))
	{
		return 13;
	}
	else if (cekCommand(kata, "HAPUS_UTAS", 11-1))
	{
		return 14;
	}
	else if (cekCommand(kata, "CETAK_UTAS", 11-1))
	{
		return 15;
	}
	else if (cekCommand(kata, "DAFTAR_TEMAN", 13-1))
	{
		return 16;
	}
	else if (cekCommand(kata, "HAPUS_TEMAN", 12-1))
	{
		return 17;
	}
	else if (cekCommand(kata, "BALAS", 6-1))
	{
		return 18;
	}
	else if (cekCommand(kata, "BALASAN", 8-1))
	{
		return 19;
	}
	else if (cekCommand(kata, "HAPUS_BALASAN", 14-1))
	{
		return 20;
	}
	else if (cekCommand(kata, "BUAT_DRAFT", 11-1))
	{
		return 21;
	}
	else if (cekCommand(kata, "LIHAT_DRAFT", 12-1))
	{
		return 22;
	}
	else if (cekCommand(kata, "TAMBAH_TEMAN", 13-1))
	{
		return 23;
	}
	else if (cekCommand(kata, "DAFTAR_PERMINTAAN_PERTEMANAN", 29-1))
	{
		return 24;
	}
	else if (cekCommand(kata, "SETUJUI_PERTEMANAN", 19-1))
	{
		return 25;
	}
	else if (cek(kata, "UBAH_KICAUAN")) {
		return 26;
	}
	else{
		return -1;
	}
}