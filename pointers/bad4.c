#include <stdio.h>

int *f1()
{
    int x = 42;
    int *xp = &x;
    printf("xp=%p\n", xp);
    return xp;
}

void f2()
{
    int y = 0;
    printf("&y=%p\n", &y);
}

int main()
{
    int *p1 = f1();
    printf("p1=%p\n", p1);
    printf("*p1=%i\n", *p1);

    f2();

    /* danger will robinson! */
    printf("*p1=%i\n", *p1);

    return 0;
}
