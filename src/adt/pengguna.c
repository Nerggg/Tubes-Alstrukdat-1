#include <stdio.h>
#include "pengguna.h"
#include "../feat/operational.c"
#include "../feat/io.c"

void emptyuser(Word *currentUser) {
    currentUser->TabWord[0] = ';';
    currentUser->TabWord[1] = ';';
    currentUser->TabWord[2] = ';';
    currentUser->Length = 3;
}

void daftar(UserDB *user, Word *currentUser) {
    Word temp;
    Word passWord;

    if (!cek(*currentUser, ";;;")) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        return;
    }

    // Mengecek panjang nama
    printf("Masukkan nama:\n"); 
    temp = bacakalimat();
    while (temp.Length > 20) {
        printf("Nama terlalu panjang.\n");
        printf("Masukkan nama:\n"); 
        temp = bacakalimat();
    }        

    // mengecek apakah nama sudah ada di database
    boolean ada = false;
        
    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(temp, user->db[i].nama)) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            ada = true;
            break;
        }
    }

    while (ada) {
        printf("Masukkan nama:\n"); 
        temp = bacakalimat();
        for (int i = 0; i < user->Neff; i++) {
            if (ceksama(temp, user->db[i].nama)) {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                ada = true;
                break;
            }
        }
        ada = false;
    }
    
    // ketika nama memenuhi spesifikasi, nama diletakkan ke database
    user->db[user->Neff].nama = temp;

    printf("Masukkan kata sandi:\n"); 
    temp = bacakalimat();
    user->db[user->Neff].pass = temp;

    user->Neff++;
}


void masuk(UserDB *user, Word *currentUser) {
    // Mengecek apakah pengguna sudah login
    if (cek(*currentUser, ";;;")) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
        return;
    }

    boolean ada = false;
    int idx;
    Word temp;
    printf("Masukkan nama: ");
    temp = bacakalimat();

    for (int i = 0; i < user->Neff; i++) {
        if (ceksama(temp, user->db[i].nama)) {
            ada = true;
            idx = i;
            break;
        }
    }

    while (!ada) {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        printf("Masukkan nama: ");
        temp = bacakalimat();

        for (int i = 0; i < user->Neff; i++) {
            if (ceksama(temp, user->db[i].nama)) {
                ada = true;
                idx = i;
                break;
            }
        }
    }

    printf("Masukkan kata sandi: ");
    temp = bacakalimat();

    while (!ceksama(temp, user->db[idx].pass)) {
        printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
        printf("Masukkan kata sandi: ");
        temp = bacakalimat();
    }

    if (ceksama(temp, user->db[idx].pass)) {
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", temp.TabWord);
        *currentUser = user->db[idx].nama;
        return;
    }
}

void keluar(Word *currentUser) {
    // Mengecek apakah pengguna sudah login
    if (!cek(*currentUser, ";;;")) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }

    // Mengubah status login pengguna menjadi tidak login
    emptyuser(currentUser);
    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    return;
}
