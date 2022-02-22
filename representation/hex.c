#include <stdio.h>

int main()
{
    int x;
    /* the user can enter a base 10 number
     * or 0x with a hex number */
    printf("Enter an int: ");
    scanf("%i", &x);

    /* %i displays the value in decimal
     * %x displays the value in hex (with lowercase a-f) */
    printf("%i == 0x%x\n", x, x);
    return 0;
}
