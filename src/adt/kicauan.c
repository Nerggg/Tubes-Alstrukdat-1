#include<stdio.h>
#include <stdlib.h>
#include "kicauan.h"
#include "../feat/operational.c"
#include "listdinkicauan.c"


ListDinkicau kicauanku;
int lastIDKicau;


void kicau(UserDB *user,Word *currentUser)
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
    CreateListDinkicau(&kicauanku, 100);
    insertLastkicau(&kicauanku, newKicauan);
    newKicauan.id = kicauanku.neff;
    newKicauan.text = text;
    newKicauan.like = 0;
    newKicauan.author = user->db[0].nama;
    newKicauan.datetime = CurrentDatetime();
    newKicauan.jakunkicau = user->db[0].jakun;



    // Mencetak kicauan
    printf("Kicauan Anda berhasil ditambahkan!\n");
    displaykicauan(&newKicauan);


}

Kicau displaykicauan(Kicau *kicauan)
{
    printf("| ID = %d\n", kicauan->id);
    printf("| %s\n", kicauan->author);
    printf("| %s\n", DateTimeToString(kicauan->datetime)); 
    printf("| %s\n", kicauan->text);
    printf("| Disukai: %d\n", kicauan->like);
}


Kicau suka_kicauan(UserDB *user,int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
    } else{
        if (cekKata(lKicau->buff[0].jakunkicau,"Publik")) {  
       printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }else{
        lKicau->buff[0].like++;
        displaykicauan(lKicau->buff);}
    }


    
}

void ubah_kicauan(UserDB *user,int id)
{
    ListDinkicau *lKicau = cariKicauan(&kicauanku,id);
    if (lKicau == NULL) {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
        return;
    }

    for (int i = 0; i < lKicau->neff; i++) {
        Kicau ubahkicau = lKicau->buff[i];
    }

    
    if (ceksama((lKicau->buff[0].author),(user->db[0].nama))) {
    printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
    return;
    }


    // Masukkan kicauan baru
    printf("Masukkan kicauan baru: ");
    lKicau->buff[0].text = bacakalimat();


    // Cetak informasi kicauan yang baru diubah
    printf("Selamat! kicauan telah diterbitkan!\n");
    displaykicauan(lKicau->buff);
}