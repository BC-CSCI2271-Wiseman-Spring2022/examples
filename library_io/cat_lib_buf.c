#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s buffer_size\n", argv[0]);
        exit(1);
    }

    // assume the first arg is an int
    int size = atoi(argv[1]);

    char *buf = (char *)malloc(size*sizeof(char));

    int chars_read = fread(buf, sizeof(char), size, stdin);
    if (ferror(stdin))
    {
        perror("fread");
        exit(1);
    }

    while (!feof(stdin))
    {
        int chars_written = fwrite(buf, sizeof(char), chars_read, stdout);
        if (ferror(stdout))
        {
            perror("fwrite");
            exit(1);
        }
        if (chars_written != chars_read)
        {
            printf("write issue!");
            exit(1);
        }

        chars_read = fread(buf, sizeof(char), size, stdin);
        if (ferror(stdin))
        {
            perror("fread");
            exit(1);
        }
    }

    free(buf);

    return 0;
}
