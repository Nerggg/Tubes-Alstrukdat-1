#include <stdio.h>
#include "../adt/kicauan.h"
#include "../adt/utas.h"
#include "../feat/io.h"
#include "../feat/misc.h"
#include "../feat/operational.h"
#include "../adt/balasan.h"

int main (){
    UserDB user;
    Word currentUser;
    ListDinkicau kicauan;
    ListDintree ltree;
    Graf teman;
    ListUtas utas;
    ListStack sl;
    int idkicau;
    int idbalasan;
    Word idkicauw ;
    Word idbalasanw;
    Word namafolder = {"config-1", 8};
    driverbacaconfig(&user, &utas, &kicauan,&ltree ,&sl , &teman, namafolder );
    masuk(&user, &currentUser);
    printf("Masukan id kicau yang ingin dibalas: ");
    idkicauw = baca();
    idkicau = wtoi(idkicauw);
    printf("Masukan id balasan yang ingin dibalas: ");
    idbalasanw = baca();
    idbalasan = wtoi(idbalasanw);
    Balas(user, currentWord, kicauan, &ltree, teman, idkicau, idbalasan);
    printf("Masukan id kicau yang ingin dibalas: ");
    idkicauw = baca();
    idkicau = wtoi(idkicauw);
    printf("Masukan id balasan yang ingin dibalas: ");
    idbalasanw = baca();
    idbalasan = wtoi(idbalasanw);
    Balas(user, currentWord, kicauan, &ltree, teman, idkicau, idbalasan);
    printf ("masukan No id kicauan yg ingin dilihat balasanya :");
    idkicauw = baca();
    idkicau = wtoi(idkicauw);
    Balasan(user, currentWord, kicauan, ltree ,teman, idkicau);
    printf ("masukan No id kicauan yg ingin dihapus balasanya :");
    idkicauw = baca();
    idkicau = wtoi(idkicauw);
    printf ("masukan No id kicauan yg ingin dihapus balasanya :");
    idbalasanw = baca();
    idbalasan = wtoi(idbalasanw);
    printf ("masukan No id kicauan yg ingin dilihat balasanya :");
    idkicauw = baca();
    idkicau = wtoi(idkicauw);
    Balasan(user, currentWord, kicauan, ltree ,teman, idkicau);

}

