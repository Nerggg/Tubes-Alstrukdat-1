#include "teman.h"
#include <stdio.h>
#include "../feat/operational.h"
#include "../feat/misc.h"
#include "boolean.h"

// Deklarasi fungsi-fungsi yang ada pada teman.h
void daftarteman(Word currentUser, UserDB *listAkun, Graf teman);
void hapusteman(Word currentUser, UserDB *listAkun, Graf *teman);
boolean cekteman(Pengguna akun, Pengguna cekakun, UserDB *listAkun, Graf teman);

int main() {
    Word currentUser = {"username", 8}; // Ganti dengan username yang benar
    UserDB listAkun;
    // Inisialisasi listAkun
    // ...
    Graf teman;
    // Inisialisasi teman
    // ...

    // Memanggil fungsi daftarteman
    daftarteman(currentUser, &listAkun, teman);

    // Memanggil fungsi hapusteman
    hapusteman(currentUser, &listAkun, &teman);

    // Memanggil fungsi cekteman
    Pengguna akun1; // Ganti dengan pengguna yang benar
    Pengguna akun2; // Ganti dengan pengguna yang benar
    boolean result = cekteman(akun1, akun2, &listAkun, teman);
    
    if (result) {
        printf("Mereka adalah teman.\n");
    } else {
        printf("Mereka bukan teman.\n");
    }

    return 0;
}
