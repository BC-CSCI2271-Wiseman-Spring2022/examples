#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val;

    printf("Enter an integer: ");
    int ret = scanf("%i", &val);
    if (ret == 0)
    {
        printf("That's not an integer!\n");
        exit(1);
    }
    if (ret == EOF)
    {
        printf("No values provided!\n");
        exit(1);
    }

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
