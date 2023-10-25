#ifndef FOO_H
#define FOO_H

#include <stdio.h>

typedef struct
{
    int Bar;
} Foo;

#define Bar(foo) (foo).Bar

void CreateFoo(Foo *foo, int bar);
/* I.S. : foo terinisialisasi */
/* F.S. : foo terdefinisi */

void TambahBar(Foo *foo, int x);
/* I.S. : foo terdefinisi */
/* F.S. : Bar(foo) bertambah sebanyak x */

void KurangBar(Foo *foo, int x);
/* I.S. : foo terdefinisi */
/* F.S. : Bar(foo) berkurang sebanyak x */

void TulisFoo(Foo foo);
/* I.S. : foo sembarang */
/* F.S. : Nilai Bar(foo) tertulis pada layar */

#endif