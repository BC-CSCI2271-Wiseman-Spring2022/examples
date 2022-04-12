#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include "sorted_list.h"

int main()
{
    int longest_name_length = 0;
    node *filenames = NULL;

    struct dirent *de;
    DIR *d = opendir(".");
    if (d == NULL)
    {
        perror("opendir");
        exit(1);
    }

    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        add_node(&filenames, strdup(de->d_name));
        if (strlen(de->d_name) > longest_name_length)
        {
            longest_name_length = strlen(de->d_name);
        }
    }

    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    node *filename = filenames;
    while (filename != NULL)
    {
        struct stat finfo;
        if (stat(filename->value, &finfo) == -1)
        {
            perror(filename->value);
            continue;
        }

        printf("%*s %li\n", -longest_name_length, filename->value, finfo.st_size);

        filename = filename->next;
    }

    free_list(&filenames);

    return 0;
}
