#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char *dictionary[134];
    dictionary[128] = "the";
    dictionary[129] = "and";
    dictionary[130] = "for";
    dictionary[131] = "you";
    dictionary[132] = "are";
    dictionary[133] = "but";

    char cur_string[4];
    int read_return = read(STDIN_FILENO, cur_string, 3*sizeof(char));
    if (read_return < 0)
    {
        perror("read");
        exit(1);
    }
    cur_string[3] = '\0';

    while (read_return != 0)
    {
        unsigned int i;
        for (i=128; i<134; ++i)
        {
            if (strcmp(dictionary[i], cur_string) == 0)
            {
                break;
            }
        }

        if (i != 134)
        {
            char c = (char)i;
            if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
            {
                perror("write");
                exit(1);
            }

            read_return = read(STDIN_FILENO, cur_string, 3*sizeof(char));
            if (read_return < 0)
            {
                perror("read");
                exit(1);
            }
            cur_string[read_return] = '\0';
        }
        else
        {
            if (write(STDOUT_FILENO, &cur_string[0], sizeof(char)) != sizeof(char))
            {
                perror("write");
                exit(1);
            }

            cur_string[0] = cur_string[1];
            cur_string[1] = cur_string[2];
            read_return = read(STDIN_FILENO, &cur_string[2], sizeof(char));
            if (read_return < 0)
            {
                perror("read");
                exit(1);
            }
            if (read_return == 0)
            {
                cur_string[2] = '\0';
            }
            else
            {
                cur_string[3] = '\0';
            }
        }
    }

    int cur_string_len = strlen(cur_string);
    if (cur_string_len != 0)
    {
        if (write(STDOUT_FILENO, cur_string, cur_string_len) != cur_string_len)
        {
            perror("write");
            exit(1);
        }
    }

    return 0;
}
