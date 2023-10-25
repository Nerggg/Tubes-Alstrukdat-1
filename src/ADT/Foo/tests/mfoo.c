#include <stdio.h>
#include "../foo.h"

int main()
{
    int type, bar;
    Foo foo;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test CreateFoo
        scanf("%d", &bar);
        CreateFoo(&foo, bar);

        printf("%d\n", Bar(foo));
        break;

    case 2:
        // Test TambahBar
        scanf("%d", &bar);
        CreateFoo(&foo, bar);

        scanf("%d", &bar);
        TambahBar(&foo, bar);

        printf("%d\n", Bar(foo));
        break;

    case 3:
        // Test KurangBar
        scanf("%d", &bar);
        CreateFoo(&foo, bar);

        scanf("%d", &bar);
        KurangBar(&foo, bar);

        printf("%d\n", Bar(foo));
        break;

    case 4:
        // Test TulisFoo
        scanf("%d", &bar);
        CreateFoo(&foo, bar);

        TulisFoo(foo);

        break;
    }

    return 0;
}