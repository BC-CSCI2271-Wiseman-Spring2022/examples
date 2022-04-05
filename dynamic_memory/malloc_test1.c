#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ADDRS 10

int main(int argc, char **argv)
{
    printf("sbrk(0) = %p\n", sbrk(0));

    /*
    char *dynvar1 = (char *)malloc(sizeof(char)*4);
    for (int i=2; i<=10; ++i)
    {
        size_t num_bytes = sizeof(char) * 4 * i;
        char *dynvar2 = (char *)malloc(num_bytes);

        int diff = dynvar2-dynvar1;
        printf("dynvar(%2lu bytes) = %p, size = %i\n", num_bytes-4, dynvar1, diff);

        dynvar1 = dynvar2;
    }
    printf("dynvar(%2lu bytes) = %p\n", sizeof(char)*4*(10), dynvar1);
    */

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

