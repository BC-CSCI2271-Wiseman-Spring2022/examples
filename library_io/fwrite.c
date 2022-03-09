#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        perror("output.txt");
        exit(1);
    }

    char msg[] = "Tea, Earl Grey, Hot";
    int num_wrote = fwrite(msg, sizeof(char), strlen(msg), fp);
    if (ferror(fp))
    {
        perror("fwrite");
        exit(1);
    }
    if (num_wrote != strlen(msg)) 
    {
        printf("fwrite problem!");
        exit(1);
    }

    unsigned int vals[] = { 10, 69, 110, 103, 97, 103, 101, 33, 10 };
    num_wrote = fwrite(vals, sizeof(unsigned int), 9, fp);
    if (ferror(fp))
    {
        perror("fwrite");
        exit(1);
    }
    if (num_wrote != 9) 
    {
        printf("fwrite problem!");
        exit(1);
    }

    if (fclose(fp) != 0)
    {
        perror("fclose");
    }
    return 0;
}
