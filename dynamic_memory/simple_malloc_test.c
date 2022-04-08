#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "simple_malloc.h"

#define NUM_ADDRS 100

int main(int argc, char **argv)
{
    printf("sbrk(0) = %p\n", sbrk(0));

    char *addrs[NUM_ADDRS];
    size_t sizes[NUM_ADDRS];
    for (int i=0; i<NUM_ADDRS; ++i)
    {
        sizes[i] = sizeof(char) * 4 * (i+1);
        addrs[i] = (char *)simple_malloc(sizes[i]);
    }

    size_t *size_addr;
    for (int i=0; i<NUM_ADDRS-1; ++i)
    {
        int diff = addrs[i+1]-addrs[i];
        size_addr = (size_t *)(addrs[i]-8);
        printf("addr(%2lu bytes) = %p, size = %i, addr[-8] = %lu\n", 
                sizes[i], addrs[i], diff, *size_addr);
    }

    size_addr = (size_t *)(addrs[NUM_ADDRS-1]-8);
    printf("addr(%2lu bytes) = %p, addr[-8] = %lu\n", 
            sizes[NUM_ADDRS-1], addrs[NUM_ADDRS-1], *size_addr);

    printf("sbrk(0) = %p\n", sbrk(0));

    char *stuff = (char *)simple_malloc(10000);
    size_addr = (size_t *)(stuff-8);
    printf("addr(10000 bytes) = %p, addr[-8] = %lu\n", stuff, *size_addr);


    return 0;
}

