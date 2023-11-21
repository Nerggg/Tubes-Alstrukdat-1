#ifndef BALASAN_H
#define BALASAN_H

#include "datetime.h"
#include "wordmachine.h"
#include "kicauan.h"
#include "../feat/misc.h"
#include "../feat/operational.h"

/* PROTOTYPE */    


int countValuesInTree(Addresst node);

Addresst searchIdx(List t, int idbalasan);

void addBalasan(List *t, int id,Kicau kicauan);

int findLargestIdx(List t, int *largestValue);

void deleteChild(List *t, int id);

void printtree(UserDB user,Pengguna currentPengguna,Graf teman, Addresst p, int idkicau, int depth);

void Balas(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree *ltree,Graf teman, int idkicau, int idbalasan);

void Balasan(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree ltree,Graf teman, int idkicau);

void Hapus_Balasan(UserDB user,Word currentUser,ListDinkicau kicau,ListDintree *ltree, int idkicau, int idbalasan);

#endif