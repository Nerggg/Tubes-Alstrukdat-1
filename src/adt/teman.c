#include "teman.h"
#include <stdio.h>
#include "../feat/operational.h"
#include "../feat/misc.h"
#include "boolean.h"

void daftarteman(boolean login, Pengguna akun, UserDB *listAkun, Graf teman)
{
    if (login)
    {
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
        if (isEmptylistGraf(l))
        {
            PrintWord(akun.nama);
            printf(" belum mempunyai teman\n");
        }
        else
        {
            PrintWord(akun.nama);
            printf(" memiliki %d teman\n", listEffGraf(l));
            printf("Daftar teman ");
            PrintWord(akun.nama);
            printf("\n");
            for (int j = 0; j < CAPACITYGRAF; j++)
            {
                if (ELMTLISTGRAF(l, i) == 1)
                {
                    printf("| ");
                    PrintWord(listAkun->db[j].nama);
                    printf("\n");
                }
            }
        }
    }
    else
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir");
    }
}

void hapusteman(boolean login, Pengguna akun, UserDB *listAkun, Graf *teman)
{
    if (login)
    {
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
        STARTWITHBLANK();
        Word akunHapus = currentWord;
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
            STARTWORD;
            ADVWORD;
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
    int i = 0;
    int ID1, ID2;
    while (i < listAkun->Neff)
    {
        if (ceksama(listAkun->db[i].nama, akun.nama))
        {
            ID1 = i;
            break;
        }
        else
        {
            i++;
        }
    }
    i = 0;
    while (i < listAkun->Neff)
    {
        if (ceksama(listAkun->db[i].nama, cekakun.nama))
        {
            ID2 = i;

            break;
        }
        else
        {
            i++;
        }
    }

    if (teman.mem[ID1][ID2] == 1 && teman.mem[ID2][ID1] == 1) {
        // printf("idnya %s itu %d\n", listAkun->db[ID1].nama.TabWord, ID1);        
        // printf("idnya %s itu %d\n", listAkun->db[ID2].nama.TabWord, ID2);            
        flag = true;
    }

    return flag;
}
