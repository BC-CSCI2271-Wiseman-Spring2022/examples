#include <stdio.h>

void probe(unsigned long *addr, int offset)
{
    unsigned long *cur;
    //for (cur = addr-offset; cur <= addr+1; cur += 1)
    for (cur = addr+offset; cur >= addr-1; cur -= 1)
    {
        printf("addr: %p, ", cur);
        fflush(stdout);
        printf("value: 0x%lx\n", *cur);
        fflush(stdout);
    }
    printf("\n");
}

unsigned long h(unsigned long n)
{
    unsigned long res = n+3;
    printf("h() probe:\n");
    probe(&res, 15);
    return res;
}

unsigned long g(unsigned long n)
{
    unsigned long res = h(n+2);
    printf("g() probe:\n");
    probe(&res, 10);
    return res;
}

unsigned long f(unsigned long n)
{
    unsigned long res = g(n+1);
    printf("f() probe:\n");
    probe(&res, 5);
    return res;
}

int main()
{
    printf("&probe() = %p\n", &probe);
    printf("&h()     = %p\n", &h);
    printf("&g()     = %p\n", &g);
    printf("&f()     = %p\n", &f);
    printf("&main()  = %p\n", &main);

    unsigned long x = f(10);
    printf("x=%lu\n", x);
    return 0;
}
