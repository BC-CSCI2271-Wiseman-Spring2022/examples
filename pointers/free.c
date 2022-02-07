#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: malloc2 size\n");
        return 1;
    }

    /* assume argv[1] is an int */
    int n = atoi(argv[1]);

    /* could also use calloc(n,sizeof(double)) */
    double *a = (double *)malloc(n*sizeof(double));
    if (a == NULL)
    {
        printf("Memory error!\n");
        return 1;
    }

    for (int i=0; i<n; ++i)
    {
        a[i] = 3.14159*i;
    }

    for (int i=0; i<n; ++i)
    {
        printf("&a[%i]=%p; a[%i]=%g\n", i, &a[i], i, a[i]);
    }

    free(a);

    return 0;
}
