#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ADDRS 20

int main(int argc, char **argv)
{
    printf("sbrk(0) = %p\n", sbrk(0));

    char *addrs[NUM_ADDRS];
    size_t sizes[NUM_ADDRS];
    for (int i=0; i<NUM_ADDRS; ++i)
    {
        sizes[i] = sizeof(char) * 4 * (i+1);
        addrs[i] = (char *)malloc(sizes[i]);
    }

    for (int i=0; i<NUM_ADDRS-1; ++i)
    {
        int diff = addrs[i+1]-addrs[i];
        printf("addr(%2lu bytes) = %p, size = %i\n", sizes[i], addrs[i], diff);
    }

    printf("addr(%2lu bytes) = %p\n", sizes[NUM_ADDRS-1], addrs[NUM_ADDRS-1]);

    printf("sbrk(0) = %p\n", sbrk(0));

    return 0;
}

