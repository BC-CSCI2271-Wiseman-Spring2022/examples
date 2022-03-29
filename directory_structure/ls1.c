#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    struct stat finfo;

    for (int i=1; i<argc; ++i)
    {
        if (stat(argv[i], &finfo) == 0)
        {
            printf("%s %li\n", argv[i], finfo.st_size);
        }
        else
        {
            printf("%s: file not found\n", argv[i]);
        }
    }
    return 0;
}
