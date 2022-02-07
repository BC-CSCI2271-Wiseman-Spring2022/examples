#include <stdio.h>
#include <stdlib.h>

int *f1()
{
    int *xp = (int *)malloc(sizeof(int));
    if (xp == NULL)
    {
        return NULL;
    }
    *xp = 42;
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
    if (p1 == NULL)
    {
        printf("Memory error!");
        return 1;
    }

    printf("p1=%p\n", p1);
    printf("*p1=%i\n", *p1);

    f2();

    /* danger removed */
    printf("*p1=%i\n", *p1);

    return 0;
}
