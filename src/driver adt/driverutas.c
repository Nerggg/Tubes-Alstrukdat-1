#include <stdio.h>
#include "../adt/utas.h"
#include "../adt/kicauan.h"
#include "../feat/io.h"
#include "../feat/misc.h"
#include "../feat/operational.h"

int main() {
    ListDinkicau kicauan;
    ListUtas utas;
    UserDB user;
    Word currentUser;
    Word temp;
    Graf teman;
    Word namafolder = {"config-1", 8};

    driverbacaconfig(&user, &utas, &kicauan, &teman, namafolder);

    cetakUtas(utas, 1);
    cetakUtas(utas, 2);
    cetakUtas(utas, 3);

    masuk(&user, &currentUser);

    int id;
    printf("\nMasukkan id kicauan yang ingin ditambahkan utas\n");
    temp = baca();
    id = wtoi(temp);
    isiUtas(&utas, currentUser, kicauan, id);

    cetakUtas(utas, 1);
    cetakUtas(utas, 2);
    cetakUtas(utas, 3);
}