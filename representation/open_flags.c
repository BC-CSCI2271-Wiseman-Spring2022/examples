#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
    printf("O_RDONLY=");
    print_binary(O_RDONLY);
    printf("\n");

    printf("O_WRONLY=");
    print_binary(O_WRONLY);
    printf("\n");

    printf("O_CREAT=");
    print_binary(O_CREAT);
    printf("\n");

    printf("O_TRUNC=");
    print_binary(O_TRUNC);
    printf("\n");

    printf("O_APPEND=");
    print_binary(O_APPEND);
    printf("\n");


    return 0;
}

