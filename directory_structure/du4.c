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

    printf("Processing directory: %s\n", dir);
    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        if (strcmp(de->d_name, "..") == 0)
        {
            continue;
        }

        int new_length = strlen(dir) + 1 + strlen(de->d_name) + 1;
        char *path = (char *)malloc(new_length * sizeof(char));
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, de->d_name);

        struct stat finfo;
        if (stat(path, &finfo) == -1)
        {
            perror(path);
            free(path);
            continue;
        }

        printf("Processing file: %s\n", path);
        if (S_ISDIR(finfo.st_mode) && strcmp(de->d_name, ".") != 0)
        {
            size += find_size(path);
        }
        else
        {
            size += finfo.st_size;
        }

        free(path);
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
