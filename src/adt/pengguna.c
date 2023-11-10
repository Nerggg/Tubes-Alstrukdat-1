#include <stdio.h>
#include "pengguna.h"
#include "../feat/operational.c"
#include "../feat/io.c"
#include "./pcolor.c"

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
    if (!cek(*currentUser, ";;;")) {
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
        *currentUser = user->db[idx].nama;
        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n", *currentUser);
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

void displayNama(Pengguna P){
    for(int i=0;i<P.nama.Length;i++){
        printf("%c",P.nama.TabWord[i]);
    }
}

void displayBioAkun(Pengguna P){
    for(int i=0;i<P.bio.Length;i++){
        printf("%c",P.bio.TabWord[i]);
    }
}

void displayNoHP(Pengguna P){
    for(int i=0;i<P.hp.Length;i++){
        printf("%c",P.hp.TabWord[i]);
    }
}

void displayWeton(Pengguna P){
    for(int i=0;i<P.weton.Length;i++){
        printf("%c",P.weton.TabWord[i]);
    }
}

void displayPP(Pengguna P){
    for(int i=0;i<(P.PP).rowEff;i++){
        for(int j=1;j<(P.PP).colEff;j+=2){
         //   printf("%c",MATELMT((P.PP),i,j));
            if(MATELMT((P.PP),i,j-1) == 'R'){
                print_red(MATELMT((P.PP),i,j));
            }
            if(MATELMT((P.PP),i,j-1) == 'G'){
                print_green(MATELMT((P.PP),i,j));
            }
            if(MATELMT((P.PP),i,j-1) == 'B'){
                print_blue(MATELMT((P.PP),i,j));
            }
        }
        printf("\n");
    }
}

void inputNama(Pengguna *P){
    printf("Masukkan Nama: ");
    STARTWITHBLANK();
    Word tmp;
    tmp.Length = 0;
    for(int i=0;i<currentWord.Length;i++){
        tmp.TabWord[i] = currentWord.TabWord[i];
        tmp.Length++;
    }
    if (currentWord.Length != 0){
        (*P).nama.Length = tmp.Length;
        for(int i=0;i<tmp.Length;i++){
            (*P).nama.TabWord[i] = tmp.TabWord[i];
        }
    }
}

void inputBioAkun(Pengguna *P){
    boolean valid = false;
    Word tmp;
    while(!valid){
        printf("Masukkan Bio Akun: ");
        STARTWITHBLANK();
        tmp.Length = 0;
        for(int i=0;i<currentWord.Length;i++){
            tmp.TabWord[i] = currentWord.TabWord[i];
            tmp.Length++;
        }
        
        if(tmp.Length <= 135){
            valid = true;
        }
        else{
            printf("Bio akun tidak boleh lebih panjang dari 135 karakter!\n");
        }
    }
    if (currentWord.Length != 0){
        (*P).bio.Length = tmp.Length;
        for(int i=0;i<tmp.Length;i++){
            (*P).bio.TabWord[i] = tmp.TabWord[i];
        }
    }
}

boolean cekNoHp(Word l){
    for(int i=0;i<l.Length;i++){
        if((int) l.TabWord[i] < 48 || (int) l.TabWord[i] > 57){
            return false;
        }
    }
    return true;
}

void inputNoHP(Pengguna *P){
    boolean valid = false;
    Word tmp;
    while(!valid){
        printf("Masukkan No HP: ");
        STARTWITHBLANK();
        tmp.Length = 0;
        for(int i=0;i<currentWord.Length;i++){
            tmp.TabWord[i] = currentWord.TabWord[i];
            tmp.Length++;
        }
        
        if(cekNoHp(tmp)){
            valid = true;
        }
        else{
            printf("Format no Hp salah!\n");
        }
    }
    if (currentWord.Length != 0){
        (*P).hp.Length = tmp.Length;
        for(int i=0;i<tmp.Length;i++){
            (*P).hp.TabWord[i] = tmp.TabWord[i];
        }
    }
}

void inputPP(Pengguna *P){
    printf("Masukkan foto profil:\n");
    START();
    IgnoreBlanks();
    int br = 0;
    int kl = 0;
    for(int i=0;i<5;i++){
        for(int j =0;j<10;j++){
            MATELMT((*P).PP,i,j) = currentChar;
            ADV();
            IgnoreBlanks();
        }
        IgnoreBlanks();
    }
    ROW_EFF((*P).PP) = 5;
    COL_EFF((*P).PP) = 10;
}

int lengthChar(char a[]){
    int cnt=0;
    for(int i=0;a[i] !='\0';i++){
        cnt++;
    }
    return cnt;
}

boolean cekKata(Word a,char b[]){
    if(a.Length!= lengthChar(b)){
        return false;
    }
    for(int i=0;i<a.Length;i++){
        if(a.TabWord[i]!=b[i]){
            return false;
        }
    }
    return true;
}

boolean cekWeton(Word l){
   // Pahing, Kliwon, Wage, Pon, dan Legi 
   if(cekKata(l,"Pahing") || cekKata(l,"Kliwon") || cekKata(l,"Wage") || cekKata(l,"Pon") || cekKata(l,"Legi")){
    return true;
   }
   return false;
}

void inputWeton(Pengguna *P){
    boolean valid = false;
    Word tmp;
    while(!valid){
        printf("Masukkan Weton: ");
        STARTWITHBLANK();
        if (currentWord.Length != 0){
            tmp.Length = 0;
            for(int i=0;i<currentWord.Length;i++){
                tmp.TabWord[i] = currentWord.TabWord[i];
                tmp.Length++;
            }
            
            if(cekWeton(tmp)){
                valid = true;
            }
            else{
                printf("Masukkan weton salah\n");
            }
        }
        else{
            valid = true;
        }
    }
    if (currentWord.Length != 0){
        (*P).weton.Length = tmp.Length;
        for(int i=0;i<tmp.Length;i++){
            (*P).weton.TabWord[i] = tmp.TabWord[i];
        }
    }
}

void gantiProfil(Pengguna *P)
// I.S : Menerima input berupa profil yang ingin diganti
// F.S : Profil berhasil diganti
{
    printf("| Nama: ");
    displayNama(*P);
    printf("\n");
    printf("| Bio Akun: ");
    displayBioAkun(*P);
    printf("\n");
    printf("| No HP: ");
    displayNoHP(*P);
    printf("\n");
    printf("| Weton: ");
    displayWeton(*P);
    printf("\n");

    printf("Masukkan data baru\n");
    inputBioAkun(&(*P));
    inputNoHP(&(*P));
    inputWeton(&(*P));
    printf("Profil Anda sudah berhasil diperbarui!\n");
}

void ubahFotoProfil (Pengguna *P)
{
    printf("| PP:\n ");
    printf("\n");
    displayPP(*P);
    printf("\n");
    printf("Masukkan Foto Profil Baru\n");
    inputPP(&(*P));
    printf("Foto profil anda sudah berhasil diganti!\n");
}

void displayProfil(Pengguna P)
{
    printf("| Nama: ");
    displayNama(P);
    printf("\n");
    printf("| Bio Akun: ");
    displayBioAkun(P);
    printf("\n");
    printf("| No HP: ");
    displayNoHP(P);
    printf("\n");
    printf("| Weton: ");
    displayWeton(P);
    printf("\n");
    printf("| PP:\n ");
    printf("\n");
    displayPP(P);
    printf("\n");
}

void aturJenisAkun (Pengguna *P){
    if(cekKata((*P).jakun,"Publik")){
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        STARTWITHBLANK();
        Word tmp;
        tmp.Length = 0;
        for(int i=0;i<currentWord.Length;i++){
            tmp.TabWord[i] = currentWord.TabWord[i];
            tmp.Length++;
        }
        if (cekKata(tmp,"YA")){
            char newJakun[6]="Privat";
            for(int i=0;i<6;i++){
                (*P).jakun.TabWord[i] = newJakun[i];
            }
        }
    }
    else if(cekKata((*P).jakun,"Privat")){
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        STARTWITHBLANK();
        Word tmp;
        tmp.Length = 0;
        for(int i=0;i<currentWord.Length;i++){
            tmp.TabWord[i] = currentWord.TabWord[i];
            tmp.Length++;
        }
        if (cekKata(tmp,"YA")){
            char newJakun[6]="Publik";
            for(int i=0;i<6;i++){
                (*P).jakun.TabWord[i] = newJakun[i];
            }
        }
    }
    printf("Akun anda sudah diubah menjadi akun ");
    for(int i=0;i<6;i++){
        printf("%c",(*P).jakun.TabWord[i]);
    }
    printf(".\n");
}
