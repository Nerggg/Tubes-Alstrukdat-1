#include "pertemanan.h"
#include "prioqueue.h"
#include <stdio.h>
#include "../feat/misc.h"
#include "../feat/operational.h"

void tambahteman(Word currentUser, UserDB* listakun, Graf Teman, prioqueuefren* Q){
    prioqueuefren quser, qsisa;
    boolean login = !cek(currentUser, ";;;");
    if (login)
    {
        Pengguna akunlogin;
        for (int i = 0; i < listakun->Neff; i++) {
            if (ceksama(currentUser, listakun->db[i].nama)) {
                akunlogin = listakun->db[i];
            }
        }
        int idAkun;
        int i = 0;
        boolean found = false;
        ListGraf l;
        CreateListGraf(&l);
        while(i < listakun->Neff && found == false)
        {
            if(ceksama(listakun->db[i].nama, akunlogin.nama))
            {
                idAkun = i;
                found = true;
            }
            else{
                i++;
            }
        }
        getOne(Teman,idAkun,&l);
        Enqueueuserprio(*Q, idAkun, &quser, &qsisa);
        if(IsEmptyPrio(quser))
        {
            printf("Masukkan nama pengguna:\n");
            Word user = bacakalimat();
            int idTeman;
            i = 0;
            found = false;
            while(i < listakun->Neff && found == false)
            {
                if(ceksama(listakun->db[i].nama, user))
                {
                    idTeman = i;
                    found = true;
                }
                else{
                    i++;
                }
            }
            if (ceksama(user, akunlogin.nama)){
                printf("Anda tidak dapat mengirim permintaan pertemanan kepada diri sendiri.\n");
            }
            else if (l.content[idTeman] == 1){
                printf("Anda sudah berteman dengan ");
                PrintWord(user);
                printf(".\n");
            }
            else
            {
                int i = HeadQ(*Q);
                boolean cek = true;
                while (i != TailQ(*Q)+1 && cek){
                    teman temp = ElmtQ(*Q,i);
                    if (temp.IDpengirim == idAkun && temp.IDpengirim == idTeman)
                    {
                        cek = false;
                    }
                    i = (i + 1) % MaxElQ(*Q);
                }
                if(found && cek){
                    teman temp;
                    temp.IDpengirim = idAkun;
                    temp.IDpenerima = idTeman;
                    temp.Jumlahteman = listEffGraf(l);
                    Enqueueprio(&qsisa, temp);
                    printf("Permintaan pertemanan kepada ");
                    PrintWord(user);
                    printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
                }
                else if (found && !cek){
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                    PrintWord(user);
                    printf(" sebelumnya. Silakan tunggu hingga permintaan Anda disetujui.\n");
                }
                else{
                    printf("Pengguna bernama ");
                    PrintWord(user);
                    printf(" tidak ditemukan.\n");
                }
            }
        }
        else{
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
        }
        concatenationprio(quser, qsisa, Q);
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void daftarpermintaanteman(Word currentUser, UserDB* listakun, prioqueuefren *Q)
{
    prioqueuefren quser, qsisa;
    boolean login = !cek(currentUser, ";;;");
    if (login)
    {
        Pengguna akunlogin;
        for (int i = 0; i < listakun->Neff; i++) {
            if (ceksama(currentUser, listakun->db[i].nama)) {
                akunlogin = listakun->db[i];
            }
        }
        int idAkun;
        int i = 0;
        boolean found = false;
        while(i < listakun->Neff && found == false)
        {
            if(ceksama(listakun->db[i].nama, akunlogin.nama))
            {
                idAkun = i;
                found = true;
            }
            else{
                i++;
            }
        }
        Enqueueuserprio(*Q, idAkun, &quser, &qsisa);
        PrintPrioQueue(currentUser, quser, *listakun);
        concatenationprio(quser, qsisa, Q);
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void setujuipermintaanteman(Word currentUser, UserDB* listakun, Graf* Teman, prioqueuefren* Q){
    Word YA = {"YA", 2};
    Word TIDAK = {"TIDAK", 5};
    prioqueuefren quser, qsisa;
    boolean login = !cek(currentUser, ";;;");
    if (login)
    {
        Pengguna akunlogin;
        for (int i = 0; i < listakun->Neff; i++) {
            if (ceksama(currentUser, listakun->db[i].nama)) {
                akunlogin = listakun->db[i];
            }
        }
        int idAkun;
        int i = 0;
        boolean found = false;
        while(i < listakun->Neff && found == false)
        {
            if(ceksama(listakun->db[i].nama, akunlogin.nama))
            {
                idAkun = i;
                found = true;
            }
            else{
                i++;
            }
        }
        Enqueueuserprio(*Q, idAkun, &quser, &qsisa);
        int idteman;
        PrintTopPrioQueueChar(quser, idAkun, *listakun, &idteman);
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        Word cmd = baca();
        teman temp;
        if(ceksama(cmd, YA)){
            Dequeueprio(&quser, &temp);
            ELMTGRAF(*Teman, idAkun, idteman) = 1;
            ELMTGRAF(*Teman, idteman, idAkun) = 1;
            printf("Permintaan pertemanan dari ");
            PrintWord(listakun->db[idteman].nama);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            PrintWord(listakun->db[idteman].nama);
            printf(".\n");
        }
        else if(ceksama(cmd, TIDAK)){
            Dequeueprio(&quser, &temp);
            printf("Permintaan pertemanan dari ");
            PrintWord(listakun->db[idteman].nama);
            printf(" telah ditolak.\n");
        }
        else{
            printf("Perintah tidak sesuai!\n\n");
        }
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}