#include <stdio.h>

void f1(int x)
{
    printf("at start of f1: &x=%p\n", &x); 
    printf("at start of f1: x=%i\n", x); 

    x += 10;

    printf("at end of f1: x=%i\n", x); 
}

int main()
{
    int x = 5; 

    printf("at start of main: &x=%p\n", &x); 
    printf("at start of main: x=%i\n", x); 

    f1(x);

    printf("at end of main: x=%i\n", x); 

    return 0;
}
