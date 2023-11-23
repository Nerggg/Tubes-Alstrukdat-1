#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "../adt/pengguna.h"
#include "../adt/utas.h"
#include "../adt/teman.h"
#include "../adt/matrix.h"
#include "../adt/draftkicauan.h"
#include "../adt/balasan.h"
#include "../adt/prioqueue.h"

Word hapusSpasi(Word kata);
void simpan(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, prioqueuefren *permintaanTeman, ListTreeBalasan *balasan, ListStack *sl);