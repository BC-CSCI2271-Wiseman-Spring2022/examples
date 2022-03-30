#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

char *build_path(char *dir, char *file)
{
    int path_length = strlen(dir) + 1 + strlen(file) + 1;
    char *full_path = (char *)malloc(path_length*sizeof(char));
    strcpy(full_path, dir);
    strcat(full_path, "/");
    strcat(full_path, file);
    return full_path;
}

int find_size(char *dir)
{
    int size = 0;
    struct stat finfo;
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

        char *full_path = build_path(dir, de->d_name);
        if (stat(full_path, &finfo) != 0)
        {
            perror(full_path);
            free(full_path);
            continue;
        }

        if (S_ISDIR(finfo.st_mode) && (strcmp(de->d_name, ".") != 0))
        {
            size += find_size(full_path);
        }
        else
        {
            size += finfo.st_size;
        }
        free(full_path);
    }
    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    return size;
}

int main()
{
    printf("%d\n", find_size("."));
    return 0;
}
