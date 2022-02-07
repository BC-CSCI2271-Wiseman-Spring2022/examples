#include <stdio.h>

int *f1()
{
    int x = 42;
    printf("&x=%p\n", &x);
    /* you will get a compiler warning here */
    return &x;
}

int main()
{
    int *p1 = f1();

    /* the compiler will "scrub" the return value because 
     * it can detect f1 is returning a local address */
    printf("p1=%p\n", p1);

    /* that means this will segfault: */
    printf("*p1=%i\n", *p1);

    return 0;
}
