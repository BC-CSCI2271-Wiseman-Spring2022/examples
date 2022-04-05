#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    long sz = sysconf(_SC_PAGESIZE);
    printf("%lu\n", sz);

    return 0;
}

