#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        perror("input.txt");
        exit(1);
    }

    printf("Got fd: %u\n", fileno(fp));

    if (fclose(fp) != 0)
    {
        perror("fclose");
    }
    return 0;
}
