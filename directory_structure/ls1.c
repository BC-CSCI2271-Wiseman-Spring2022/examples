#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    for (int i=1; i<argc; ++i)
    {
        struct stat finfo;
        if (stat(argv[i], &finfo) == -1)
        {
            perror(argv[i]);
            continue;
        }

        printf("%s %li\n", argv[i], finfo.st_size);
    }
    return 0;
}
