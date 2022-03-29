#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include "sorted_list.h"

int main()
{
    node *file_names = NULL;
    int max_length = 0;
    struct stat finfo;
    struct dirent *de;

    DIR *d = opendir(".");
    if (d == NULL) {
        perror("Couldn't open .");
        exit(1);
    }

    for (de = readdir(d); de != NULL; de = readdir(d))
    {
        add_node(&file_names, strdup(de->d_name));
        int file_name_len = strlen(de->d_name);
        if (file_name_len > max_length)
        {
            max_length = file_name_len;
        }
    }

    if (closedir(d) != 0)
    {
        perror("closedir");
    }

    for (node *cur = file_names; cur != NULL; cur = cur->next)
    {
        if (stat(cur->value, &finfo) == 0)
        {
            printf("%*s %li\n", -max_length, cur->value, finfo.st_size);
        }
        else
        {
            printf("%s: file not found\n", de->d_name);
        }
    }

    free_list(&file_names);
    return 0;
}
