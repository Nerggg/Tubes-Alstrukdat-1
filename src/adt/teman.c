#include "teman.h"
#include <stdio.h>
#include "../feat/operational.h"
#include "../feat/misc.h"
#include "boolean.h"

void daftarteman(Word currentUser, UserDB *listAkun, Graf teman)
{
    boolean login = !cek(currentUser, ";;;");
    if (login)
    {
        Pengguna akun;
        for (int i = 0; i < listAkun->Neff; i++) {
            if (ceksama(currentUser, listAkun->db[i].nama)) {
                akun = listAkun->db[i];
            }
        }

        ListGraf l;
        CreateListGraf(&l);
        int i = 0;
        boolean found = false;
        int accountID;
        while (i < listAkun->Neff && !found)
        {
            if (ceksama(listAkun->db[i].nama, akun.nama))
            {
                accountID = i;
                found = true;
            }
            else
            {
                i++;
            }
        }
        getOne(teman, accountID, &l);
        int jlhteman = listEffGraf(l) - 1;
        if (jlhteman == 0)
        {
            printf("%s belum mempunyai teman\n", akun.nama.TabWord);
        }
        else
        {
            PrintWord(akun.nama);
            printf(" memiliki %d teman\n", jlhteman);
            printf("Daftar teman ");
            PrintWord(akun.nama);
            printf("\n");
            for (int j = 0; j < CAPACITYGRAF; j++)
            {
                if (ceksama(currentUser, listAkun->db[j].nama)) {
                    continue;
                }
                if (ELMTLISTGRAF(l, j) == 1)
                {
                    printf("| %s\n", listAkun->db[j].nama.TabWord);
                }
            }
        }
    }
    else
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir");
    }
}

void hapusteman(Word currentUser, UserDB *listAkun, Graf *teman)
{
    boolean login = !cek(currentUser, ";;;");
    if (login)
    {
        Pengguna akun;
        for (int i = 0; i < listAkun->Neff; i++) {
            if (ceksama(currentUser, listAkun->db[i].nama)) {
                akun = listAkun->db[i];
            }
        }

        Word YA = {"YA", 2};
        Word TIDAK = {"TIDAK", 5};
        ListGraf l;
        CreateListGraf(&l);
        int i = 0;
        boolean found = false;
        int accountID;
        while (i < listAkun->Neff && !found)
        {
            if (ceksama(listAkun->db[i].nama, akun.nama))
            {
                accountID = i;
                found = true;
            }
            else
            {
                i++;
            }
        }
        getOne(*teman, accountID, &l);
        printf("Masukkan nama pengguna:\n");
        Word akunHapus = bacakalimat();
        found = false;
        int IDakunhapus;
        i = 0;
        while (i < CAPACITYGRAF && !found)
        {
            if (ELMTLISTGRAF(l, i) == 1 && ceksama(listAkun->db[i].nama, currentWord))
            {
                IDakunhapus = i;
                found = true;
            }
            else
            {
                i++;
            }
        }
        if (found)
        {
            printf("Apakah anda yakin ingin menghapus %s dari daftar teman Anda? (YA/TIDAK)", currentWord.TabWord);
            STARTWORD();
            ADVWORD();
            Word masukkan = currentWord;
            if (ceksama(YA, masukkan))
            {
                printf("%s berhasil dihapus dari daftar teman Anda.\n", akunHapus.TabWord);
                ELMTGRAF(*teman, accountID, IDakunhapus) = 0;
            }
            else if (ceksama(TIDAK, masukkan))
            {
                printf("Penghapusan teman dibatalkan.\n");
            }
        }
        else
        {
            printf("%s bukan teman Anda.\n", akunHapus.TabWord);
        }
    }
    else
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir");
    }
}

boolean cekteman(Pengguna akun, Pengguna cekakun, UserDB *listAkun, Graf teman)
{
    boolean flag = false;
    int idx1, idx2;
    for (int i = 0; i < listAkun->Neff; i++) {
        if (ceksama(akun.nama, listAkun->db[i].nama)) {
            idx1 = i;
            break;
        }
    }
    for (int i = 0; i < listAkun->Neff; i++) {
        if (ceksama(cekakun.nama, listAkun->db[i].nama)) {
            idx2 = i;
            break;
        }
    }

    if (teman.mem[idx1][idx2] == 1 && teman.mem[idx2][idx1] == 1) {
        flag = true;
    }
    return flag;
}
