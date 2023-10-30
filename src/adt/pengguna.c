#include <stdio.h>
#include "pengguna.h"

void daftar() {
    Word currentWord;
    Word passWord;

    if (user.db[0].status == 1) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        return;
    }
    STARTWORD();

    // Mengecek apakah nama sudah ada
    printf("Masukkan nama:\n"); 
    while (!EndWord) {
        if (strlen(currentWord.TabWord) > 20) {
        printf("Nama terlalu panjang.\n");
        } else {
            for (int i = 0; i < jumlah_pengguna; i++) {
                if (strcmp(currentWord.TabWord, user.db[i].nama.TabWord) == 0) {
                printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                return;
                }
            }

            printf("Masukkan kata sandi:\n"); 

            // Mendaftarkan pengguna baru
            strcpy(user.db[jumlah_pengguna].nama.TabWord, currentWord.TabWord);
            strcpy(user.db[jumlah_pengguna].pass.TabWord, passWord.TabWord);
            jumlah_pengguna++;

            // Menulis data ke file config
            FILE *fp = fopen("cfg/config.txt", "a");
            fprintf(fp, "%s,%s\n", user.db[jumlah_pengguna - 1].nama.TabWord, user.db[jumlah_pengguna - 1].pass.TabWord);
            fclose(fp);

            printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
            return;
        }

        CopyWord();
    }
}


void masuk() {
        // Mengecek apakah pengguna sudah login
        if (user.db[0].status == 1) {
            printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
            return;
        }

        // Tidak ada pengguna aktif
        printf("Anda belum login. Silakan login terlebih dahulu.\n");

        // memasukkan nama dan kata sandi
        char nama[20], pass[20];
        printf("Masukkan nama: ");
        scanf("%s", nama);
        printf("Masukkan kata sandi: ");
        scanf("%s", pass);

        // Mencari pengguna dengan nama dan kata sandi sesuai yang diinput
        int found = 0; // boolean untuk menandai jika pengguna ditemukan
        for (int i = 0; i < jumlah_pengguna; i++) {
            if (strcmp(nama, user.db[i].nama) == 0) {
                if (strcmp(pass, user.db[i].pass) == 0) {
                    // Pengguna ditemukan
                    user.db[i].status = 1;
                    printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", nama);
                    return;
                } else {
                    // Kata sandi tidak cocok
                    printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
                    return;
                }
                found = 1; //pengguna ditemukan
            }
        }

        // Pengguna tidak ditemukan
        if (!found) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
        }

}

void keluar() {
  // Mengecek apakah pengguna sudah login
  if (user.db[0].status == 0) {
    printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    return;
  }

  // Mengubah status login pengguna menjadi 0
  user.db[0].status = 0;
  printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
}





