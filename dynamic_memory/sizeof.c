#include <stdio.h>

int main()
{
    printf("sizeof(char)=%li\n", sizeof(char));
    printf("sizeof(int)=%li\n", sizeof(int));
    printf("sizeof(long)=%li\n", sizeof(long));
    printf("sizeof(float)=%li\n", sizeof(float));
    printf("sizeof(double)=%li\n", sizeof(double));
    printf("sizeof(long double)=%li\n", sizeof(long double));

    printf("sizeof(void *)=%li\n", sizeof(void *));
    printf("sizeof(char *)=%li\n", sizeof(char *));
    printf("sizeof(int *)=%li\n", sizeof(int *));
    printf("sizeof(long *)=%li\n", sizeof(long *));
    printf("sizeof(float *)=%li\n", sizeof(float *));
    printf("sizeof(double *)=%li\n", sizeof(double *));
    printf("sizeof(long double *)=%li\n", sizeof(long double *));
    return 0;
}
