#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    struct stat finfo;
    struct dirent *de;

    DIR *d = opendir(".");
    if (d == NULL) {
        perror("Couldn't open .");
        exit(1);
    }

    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        if (stat(de->d_name, &finfo) == 0)
        {
            printf("%s %li\n", de->d_name, finfo.st_size);
        }
        else
        {
            printf("%s: file not found\n", de->d_name);
        }
    }

    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    return 0;
}
