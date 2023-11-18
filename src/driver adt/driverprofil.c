#include<stdio.h>
#include<stdlib.h>
#include "../adt/pengguna.h"
#include "../feat/io.h"
#include "../feat/misc.h"
#include "../feat/operational.h"

int main(){
    Pengguna P1;
    char newJakun[6] = "Publik";
    P1.jakun.Length = 0;
    for(int i=0;i<6;i++){
        P1.jakun.TabWord[i] = newJakun[i];
        P1.jakun.Length++;
    }
    aturJenisAkun(&P1);
    inputNama(&P1);
    inputBioAkun(&P1);
    inputNoHP(&P1);
    inputWeton(&P1);
    inputPP(&P1);
    displayProfil(P1);
    gantiProfil(&P1);
    ubahFotoProfil(&P1);
    displayProfil(P1);
}