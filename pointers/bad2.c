#include <stdio.h>

int *f1()
{
    int x = 42;
    /* we can fool the compiler easily enough by
     * adding a pointer variable to return */
    int *xp = &x;
    printf("xp=%p\n", xp);
    return xp;
}

int main()
{
    int *p1 = f1();

    /* the compiler can't detect the issue and so
     * doesn't scrub the return value */
    printf("p1=%p\n", p1);

    /* seems to work right? just wait.. */
    printf("*p1=%i\n", *p1);

    return 0;
}
