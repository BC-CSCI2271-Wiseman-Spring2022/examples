#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int find_size(char *dir)
{
    int size = 0;

    struct dirent *de;
    DIR *d = opendir(dir);
    if (d == NULL)
    {
        perror(dir);
        exit(1);
    }

    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        if (strcmp(de->d_name, "..") == 0)
        {
            continue;
        }

        struct stat finfo;
        if (stat(de->d_name, &finfo) == -1)
        {
            perror(de->d_name);
            continue;
        }

        size += finfo.st_size;
    }

    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    return size;
}

int main()
{
    int total = find_size(".");
    printf("%i\n", total);
    return 0;
}
