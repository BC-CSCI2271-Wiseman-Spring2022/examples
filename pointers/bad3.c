#include <stdio.h>

int *f1()
{
    int x = 42;
    int *xp = &x;
    printf("xp=%p\n", xp);
    return xp;
}

int *f2()
{
    int y = 0;
    int *yp = &y;
    printf("yp=%p\n", yp);
    return yp;
}

int main()
{
    int *p1 = f1();
    printf("p1=%p\n", p1);
    printf("*p1=%i\n", *p1);

    int *p2 = f2();
    printf("p2=%p\n", p2);
    printf("*p2=%i\n", *p2);

    /* danger will robinson! */
    printf("*p1=%i\n", *p1);

    return 0;
}
