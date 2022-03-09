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

    char buf[1024];

    int num_read = fread(buf, sizeof(char), 28, fp);
    if (ferror(fp))
    {
        perror("fread");
        exit(1);
    }
    buf[num_read*sizeof(char)] = '\0';

    printf("Read %d chars: %s\n", num_read, buf);

    if (fclose(fp) != 0)
    {
        perror("fclose");
    }
    return 0;
}
