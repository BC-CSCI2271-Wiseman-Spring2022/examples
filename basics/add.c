#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: add num1 num2\n");
        return 0;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);

    double result = num1 + num2;

    printf("%g + %g = %g\n", num1, num2, result);
    return 0;
}
