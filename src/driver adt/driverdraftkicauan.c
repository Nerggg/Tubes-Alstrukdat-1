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
    Word namafolder = {"config-1", 8};
    driverbacaconfig(&user, &utas, &kicauan,&ltree ,&sl , &teman, namafolder );
    masuk(&user, &currentUser);
    BUAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    LIHAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    BUAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    LIHAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    BUAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    LIHAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    BUAT_DRAFT(&user, &currentUser,&kicauan,&sl);
    LIHAT_DRAFT(&user, &currentUser,&kicauan,&sl);
}