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

    printf("at start of main: &x=%p\n", &x); 
    printf("at start of main: x=%i\n", x); 

    f2(&x);

    printf("at end of main: x=%i\n", x); 

    return 0;
}
