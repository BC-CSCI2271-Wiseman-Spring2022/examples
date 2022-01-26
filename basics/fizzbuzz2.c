#include <stdio.h>

#define FIZZ 3
#define BUZZ 5

#define START 1
#define STOP 100

// note, try running gcc -E fizzbuzz2.c
int main()
{
    for (int i=START; i<=STOP; ++i)
    {
        if (i % FIZZ == 0) 
        {
            printf("fizz");
        } 
        if (i % BUZZ == 0)
        {
            printf("buzz");
        }
        if (i % FIZZ != 0 && i % BUZZ != 0)
        {
            printf("%i",i);
        }
        printf("\n");
    }
    return 0;
}
