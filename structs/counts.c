#include <stdio.h>
#include <stdlib.h>

struct counts
{
    int lines;
    int chars;
};

int main()
{
    struct counts file_counts;

    file_counts.lines = 10;
    file_counts.chars = 40;

    printf("%8i %8i\n", file_counts.lines, file_counts.chars);

    return 0;
}
