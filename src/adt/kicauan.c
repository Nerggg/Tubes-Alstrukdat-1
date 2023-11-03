#include<stdio.h>
#include "kicauandump.h"
#include "../feat/operational.c"
#include "../feat/io.c"

int lastIDKicau = 0;
ListDinkicau kicauanku;


void kicau(Word *currentUser)
{
    if (!cek(*currentUser, ";;;")) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    // Mengambil input dari pengguna
    Word text;
    printf("Ketik kicauan Anda: ");
    text = bacakalimat();

    // Validasi kicauan
    if (text.Length > 280) {
        printf("Kicauan tidak boleh lebih dari 280 karakter! Kicauan Anda akan terpotong secara otomatis.\n");
    }

    // Membuat kicauan baru
    Kicau newKicauan;
    newKicauan.id = ++lastIDKicau;
    newKicauan.text = text;
    newKicauan.like = 0;
    newKicauan.author = *currentUser;
    newKicauan.datetime = CurrentDatetime();

    CreateListDinkicau(&kicauanku, 100);
    insertLastkicau(&kicauanku, newKicauan);

    // Mencetak kicauan
    printf("Kicauan Anda berhasil ditambahkan!\n");
    displaykicauan(&newKicauan);


}

Kicau displaykicauan(Kicau *kicauan)
{
    char datetime;
    datetime = DateTimeToString(kicauan->datetime);

    printf("| ID = %d\n", kicauan->id);
    printf("| %s\n", kicauan->author);
    printf("| %s\n", kicauan->datetime); 
    printf("| %s\n", kicauan->text);
    printf("| Disukai: %d\n", kicauan->like);
}


Kicau suka_kicauan(int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
    }

    // Cek apakah kicauan dibuat oleh akun privat
    if (lKicau->user.db[0].author.privasi == 'P') {  
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
    }

    // Tambahkan like ke kicauan
    lKicau->db[0].like++;

    // Kembalikan kicauan
    return lKicau->db[0];
}

void ubah_kicauan(int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
        return;
    }

    for (int i = 0; i < NEFF(*lKicau); i++) {
        Kicau ubahkicau = BUFFER(*lKicau);
    }

    if (lKicau->db[0].author != user.nama) {
        printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
        return;
    }


    // Masukkan kicauan baru
    printf("Masukkan kicauan baru: ");
    lKicau->db[0].text = bacakalimat();


    // Cetak informasi kicauan yang baru diubah
    printf("Selamat! kicauan telah diterbitkan!\n");
    displaykicauan(BUFFER(*lKicau));
}