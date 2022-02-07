#include <stdio.h>
#include <stdlib.h>

void usage();

void usage()
{
    printf("usage: vlas N\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage();
    }

    /* assume argv[1] is an int */
    int n = atoi(argv[1]);

    int vla[n];

    int *dyn = (int *)malloc(sizeof(int)*n);

    printf("&vla[0]=%p\n", &vla[0]);
    printf("&dyn[0]=%p\n", &dyn[0]);

    return 0;
}
