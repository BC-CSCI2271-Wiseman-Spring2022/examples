#include <stdio.h>
#include <stdlib.h>

struct counts
{
    int lines;
    int chars;
};
typedef struct counts counter;

counter *get_counts(FILE *fp)
{
    if (fp == NULL)
    {
        return NULL;
    }

    counter *file_counts = (counter *)malloc(sizeof(counter));
    file_counts->lines = 0;
    file_counts->chars = 0;

    char buf;
    fread(&buf, sizeof(char), 1, fp);
    if (ferror(fp))
    {
        perror("fread");
        exit(1);
    }
    while (!feof(fp))
    {
        ++file_counts->chars;
        if (buf == '\n')
        {
            ++file_counts->lines;
        }

        fread(&buf, sizeof(char), 1, fp);
        if (ferror(fp))
        {
            perror("fread");
            exit(1);
        }

    }

    return file_counts;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s file\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    counter *file_counts = get_counts(fp);
    printf("%8i %8i\n", file_counts->lines, file_counts->chars);
    free(file_counts);

    if (fclose(fp) != 0)
    {
        perror("fclose");
    }
    return 0;
}
