#include <stdio.h>

int main()
{
    int val;

    printf("Enter an integer: ");
    scanf("%i", &val);

    if (val % 2 == 0)
    {
        printf("%i is even!\n", val);
    }
    else
    {
        printf("%i is odd!\n", val);
    }
    return 0;
}
