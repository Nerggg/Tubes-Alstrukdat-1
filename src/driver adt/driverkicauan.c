#include <stdio.h>
#include "../adt/kicauan.h"
#include "../adt/utas.h"
#include "../feat/io.h"
#include "../feat/misc.h"
#include "../feat/operational.h"

int main() {
    ListDinkicau kicauan;
    ListUtas utas;
    int idlikekicau, idubahkicau;
    UserDB user;
    Word currentUser;
    Word templikekicau;
    Word tempubahkicau;
    Graf teman;
    Word namafolder = {"config-1", 8};

    driverbacaconfig(&user, &utas, &kicauan, &teman, namafolder);
    masuk(&user, &currentUser);
    kicau(&user, &kicauan, &currentUser);
    printf("\nMasukkan id kicauan yang ingin disukai : \n");
    templikekicau = baca();
    idlikekicau = wtoi(templikekicau);
    suka_kicauan(user, &kicau, teman, idlikekicau, currentUser);
    printf("\nMasukkan id kicauan yang ingin diubah : \n");
    tempubahkicau = baca();
    idubahkicau = wtoi(tempubahkicau);
    ubah_kicauan(user, &kicau, idubahkicau, currentUser);
    displayallkicauan(user,kicauan, teman, currentUser);

}