#include <stdio.h>

void f2(int *p)
{
    printf("at start of f2: &p=%p\n", &p); 
    printf("at start of f2: p=%p\n", p); 
    printf("at start of f2: *p=%i\n", *p); 

    *p += 10;

    printf("at end of f2: *p=%i\n", *p); 
}

int main()
{
    int x = 5; 
    int *xptr = &x;

    printf("at start of main: &x=%p\n", &x); 
    printf("at start of main: x=%i\n", x); 

    printf("at start of main: &xptr=%p\n", &xptr); 
    printf("at start of main: xptr=%p\n", xptr); 
    printf("at start of main: *x=%i\n", *xptr); 

    f2(xptr);

    printf("at end of main: x=%i\n", x); 

    return 0;
}
