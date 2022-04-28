#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int etext;
extern int end;

int main(int argc, char **argv)
{
    void *init_sbrk = sbrk(0);

    unsigned long *start;
    unsigned long *stop;
    unsigned long *a;

    printf("&etext    = %p\n", &etext);
    printf("&end      = %p\n", &end);
    printf("init_sbrk = %p\n", init_sbrk);
    printf("&argc     = %p\n\n", &argc);

    printf("Enter a start address: ");
    scanf("%p", &start);
    printf("Enter a stop address: ");
    scanf("\n%p", &stop);
    printf("\n");

    for (a=start; a<=stop; a+=1)
    {
        printf("addr: %p, ", a);
        fflush(stdout);
        printf("value: 0x%lx\n", *a);
        fflush(stdout);
    }

    return 0;
}

