#include "savenload.h"

Word hapusSpasi(Word kata) {
    if (kata.TabWord[kata.Length] == '\n' || kata.TabWord[kata.Length] == ' ') {
        kata.TabWord[kata.Length] = '\0';
    }
    return kata;
}

void simpan(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, prioqueuefren *permintaanTeman, ListDintree *ltree, ListStack *sl) {
    printf("Masukkan nama folder penyimpanan\n");
    Word namafolder = baca();
    Word folder = namafolder;
    char awal[] = "../cfg/";
	namafolder = concat(awal, namafolder.TabWord);

    DIR *dir = opendir(namafolder.TabWord);

    folder = hapusSpasi(folder);

    if (!dir) {
        printf("Folder %s belum ada, akan dilakukan pembuatan folder terlebih dahulu.\n\n", folder.TabWord);
        printf("Mohon tunggu...\n");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n\n");

        mkdir(namafolder.TabWord, 0777);
        printf("Folder %s berhasil dibuat.\n", folder.TabWord);
    }

    printf("Anda akan melakukan penyimpanan di folder %s.\n\n", folder.TabWord);
    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n\n");

    // nulis pengguna.config
    char akhirpengguna[] = "/pengguna.config";
    namafolder = concat(namafolder.TabWord, akhirpengguna);
    FILE *file = fopen(namafolder.TabWord, "w");
    fprintf(file, "%d\n", user->Neff);
    for (int i = 0; i < user->Neff; i++) {
        Word nama = hapusSpasi(user->db[i].nama);
        Word pass = hapusSpasi(user->db[i].pass);
        Word bio = hapusSpasi(user->db[i].bio);
        Word hp = hapusSpasi(user->db[i].hp);
        Word weton = hapusSpasi(user->db[i].weton);
        Word jakun = hapusSpasi(user->db[i].jakun);
        fprintf(file, "%s\n", nama.TabWord);
        fprintf(file, "%s\n", pass.TabWord);
        fprintf(file, "%s\n", bio.TabWord);
        fprintf(file, "%s\n", hp.TabWord);
        fprintf(file, "%s\n", weton.TabWord);
        fprintf(file, "%s\n", jakun.TabWord);

        for (int j = 0; j < 5; j++) {
            fprintf(file, "%c %c %c %c %c %c %c %c %c %c\n", user->db[i].PP.mem[j][0], user->db[i].PP.mem[j][1], user->db[i].PP.mem[j][2], user->db[i].PP.mem[j][3], user->db[i].PP.mem[j][4], user->db[i].PP.mem[j][5], user->db[i].PP.mem[j][6], user->db[i].PP.mem[j][7], user->db[i].PP.mem[j][8], user->db[i].PP.mem[j][9]);
        }

        for (int j = 0; j < user->Neff; j++) {
            int k;
            for (k = 0; k < user->Neff-1; k++) {
                fprintf(file, "%d ", teman->mem[j][k]);
            }
            fprintf(file, "%d", teman->mem[j][k]);
            fprintf(file, "\n");
        }
    }
    fclose(file);

    // nulis kicauan.config
    char akhirkicauan[] = "/kicauan.config";
    namafolder = concat(concat(awal, folder.TabWord).TabWord, akhirkicauan);
    file = fopen(namafolder.TabWord, "w");
    fprintf(file, "%d\n", l->nEff);
    for (int i = 0; i < l->nEff; i++) {
        fprintf(file, "%d\n", l->buffer[i].id);
        Word text = hapusSpasi(l->buffer[i].text);
        fprintf(file, "%s\n", text.TabWord);
        fprintf(file, "%d\n", l->buffer[i].like);
        Word author = hapusSpasi(l->buffer[i].author);
        fprintf(file, "%s\n", author.TabWord);
        Word date = hapusSpasi(l->buffer[i].date);
        fprintf(file, "%s\n", date.TabWord);
    }
    fclose(file);

    // nulis utas.config
    char akhirutas[] = "/utas.config";
    namafolder = concat(concat(awal, folder.TabWord).TabWord, akhirutas);
    file = fopen(namafolder.TabWord, "w");
    fprintf(file, "%d\n", utas->neff);
    for (int i = 0; i < utas->neff; i++) {
        fprintf(file, "%d\n", utas->utasan[i].k.id);
        Word author = hapusSpasi(utas->utasan[i].k.author);
        Address p = utas->utasan[i].u;
        int jlhutas = 0;
        while (p != NULL) {
            p = p->next;
            jlhutas++;
        }
        p = utas->utasan[i].u;
        fprintf(file, "%d\n", jlhutas);
        for (int j = 0; j < jlhutas; j++) {
            Word utas = hapusSpasi(p->isi);
            fprintf(file, "%s\n", utas.TabWord);
            fprintf(file, "%s\n", author.TabWord);
            Word date = hapusSpasi(p->date);
            fprintf(file, "%s\n", date.TabWord);
            p = p->next;
        }
    }
    fclose(file);

    // nulis draf.config
    char akhirdraf[] = "/draf.config";
    namafolder = concat(concat(awal, folder.TabWord).TabWord, akhirdraf);
    file = fopen(namafolder.TabWord, "w");
    fprintf(file, "%d\n", sl->nEff);
    for (int i = 0; i < sl->nEff; i++) {
        Word author = hapusSpasi(sl->buffer[i].author);
        fprintf(file, "%s %d\n", author.TabWord, sl->buffer[i].Nstack);
        for (int j = 0; j < sl->buffer[i].TOP+1; j++) {
            Word text = hapusSpasi(sl->buffer[i].T[sl->buffer[i].TOP-j].text);
            fprintf(file, "%s\n", text.TabWord);
            Word date = hapusSpasi(sl->buffer[i].T[sl->buffer[i].TOP-j].date);
            fprintf(file, "%s\n", date.TabWord);
        }
    }
    fclose(file);

    printf("Penyimpanan telah berhasil dilakukan!\n");
}
