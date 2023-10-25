#include "foo.h"

void CreateFoo(Foo *foo, int bar)
/* I.S. : foo terinisialisasi */
/* F.S. : foo terdefinisi */
{
    Bar(*foo) = bar;
}

void TambahBar(Foo *foo, int x)
/* I.S. : foo terdefinisi */
/* F.S. : Bar(foo) bertambah sebanyak x */
{
    Bar(*foo) += x;
}

void KurangBar(Foo *foo, int x)
/* I.S. : foo terdefinisi */
/* F.S. : Bar(foo) berkurang sebanyak x */
{
    Bar(*foo) -= x;
}

void TulisFoo(Foo foo)
/* I.S. : foo sembarang */
/* F.S. : Nilai Bar(foo) tertulis pada layar */
{
    printf("%d\n", Bar(foo));
}
