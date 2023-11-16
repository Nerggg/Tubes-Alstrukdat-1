#ifndef IO_H
#define IO_H

#include "../adt/pengguna.h"
#include "../adt/utas.h"
#include "../adt/teman.h"
#include "../adt/matrix.h"

void penggunaconfig(UserDB *user, Graf *teman, Word namafolder);
void utasconfig(ListUtas *utas, ListDinkicau l, Word namafolder);
void kicauanconfig(UserDB user, ListDinkicau *l, Word namafolder);
void bacaconfig(UserDB *user, ListUtas *utas, ListDinkicau *l, Graf *teman, Word namafolder);

#endif
