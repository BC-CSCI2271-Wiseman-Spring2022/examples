#include <stdio.h>

int main()
{
    int power = 2;
    for (int exponent=1; exponent <= 16; ++exponent)
    {
        printf("2^%i = %i\n", exponent, power);
        power *= 2;
    }
    return 0;
}
