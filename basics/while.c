#include <stdio.h>

int main()
{
    int exponent = 1;
    int power = 2;
    
    while (exponent <= 16)
    {
        printf("2^%i = %i\n", exponent, power);
        power *= 2;
        ++exponent;
    }
    return 0;
}
