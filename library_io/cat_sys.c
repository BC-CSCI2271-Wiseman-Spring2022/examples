#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char c;
    int read_return = read(STDIN_FILENO, &c, sizeof(char));
    if (read_return == -1)
    {
        perror("read");
        exit(1);
    }
    while (read_return != 0)
    {
        int write_return = write(STDOUT_FILENO, &c, sizeof(char));
        if (write_return == -1)
        {
            perror("write");
            exit(1);
        }
        if (write_return != sizeof(char))
        {
            printf("write issue!");
            exit(1);
        }

        read_return = read(STDIN_FILENO, &c, sizeof(char));
        if (read_return == -1)
        {
            perror("read");
            exit(1);
        }
    }

    return 0;
}
