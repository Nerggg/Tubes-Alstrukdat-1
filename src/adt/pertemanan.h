#ifndef PERTEMANAN_H
#define PERTEMANAN_H

#include "boolean.h"
#include "wordmachine.h"
#include "graph.h"
#include "prioqueue.h"
#include "pengguna.h"

void tambahteman(Word currentUser, Pengguna akunlogin, UserDB* listakun, Graf Teman, prioqueuefren* Q);

void daftarpermintaanteman(boolean login, Pengguna akunlogin, UserDB* listakun, prioqueuefren *Q);

void setujuipermintaanteman(boolean login, Pengguna akunlogin, UserDB* listakun, Graf* Teman, prioqueuefren* Q);

#endif