#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    struct dirent *de;
    DIR *d = opendir(".");
    if (d == NULL)
    {
        perror("opendir");
        exit(1);
    }

    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        struct stat finfo;
        if (stat(de->d_name, &finfo) == -1)
        {
            perror(de->d_name);
            continue;
        }

        printf("%s %li\n", de->d_name, finfo.st_size);
    }

    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    return 0;
}
