#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    fread(&c, sizeof(char), 1, stdin);
    if (ferror(stdin))
    {
        perror("fread");
        exit(1);
    }

    while (!feof(stdin))
    {
        int write_return = fwrite(&c, sizeof(char), 1, stdout);
        if (ferror(stdout))
        {
            perror("fwrite");
            exit(1);
        }
        if (write_return != 1)
        {
            printf("write issue!");
            exit(1);
        }

        fread(&c, sizeof(char), 1, stdin);
        if (ferror(stdin))
        {
            perror("fread");
            exit(1);
        }
    }

    return 0;
}
