#ifndef IO_H
#define IO_H

#include "../adt/pengguna.h"
#include "../adt/utas.h"
#include "../adt/teman.h"
#include "../adt/matrix.h"
#include "../adt/draftkicauan.h"
#include "../adt/balasan.h"
#include "../adt/prioqueue.h"

void penggunaconfig(UserDB *user, Graf *teman, Graf *permintaanTeman, Word namafolder);
void utasconfig(ListUtas *utas, ListDinkicau l, Word namafolder);
void kicauanconfig(UserDB user, ListDinkicau *l, Word namafolder);
void balasanconfig(UserDB user, ListDinkicau kicauan, ListDintree *ltree, Word namafolder);
void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, Graf *permintaanTeman, ListDintree *ltree, ListStack *sl, Word namafolder);
void driverbacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l,Graf *teman, Graf *permintaanTeman, ListDintree *ltree, ListStack *sl, Word namafolder);

#endif
