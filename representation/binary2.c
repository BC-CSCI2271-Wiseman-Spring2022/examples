#include <stdio.h>

void print_binary(unsigned int i)
{
    int result = i / 2;
    if(result)
    {
        print_binary(result);
    }
    printf("%i", i%2);
}

int main()
{
    int x;

    printf("Enter an int: ");
    scanf("%i", &x);

    printf("%i == 0x%x == 0b", x, x);

    print_binary(x);
    printf("\n");

    return 0;
}
