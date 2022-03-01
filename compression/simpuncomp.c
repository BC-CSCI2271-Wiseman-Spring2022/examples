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

    unsigned char cur_char;

    int read_return = read(STDIN_FILENO, &cur_char, sizeof(unsigned char));
    if (read_return < 0)
    {
        perror("read");
        exit(1);
    }

    while (read_return != 0)
    {
        if (cur_char >= 128 && cur_char <= 133)
        {
            if (write(STDOUT_FILENO, dictionary[(int)cur_char], 3*sizeof(char)) != 3*sizeof(char))
            {
                perror("write");
                exit(1);
            }
        }
        else
        {
            if (write(STDOUT_FILENO, &cur_char, sizeof(char)) != sizeof(char))
            {
                perror("write");
                exit(1);
            }
        }

        read_return = read(STDIN_FILENO, &cur_char, sizeof(unsigned char));
        if (read_return < 0)
        {
            perror("read");
            exit(1);
        }
    }

    return 0;
}
