#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s buffer_size\n", argv[0]);
        exit(1);
    }

    // assume the first arg is an int
    int size = atoi(argv[1]);

    char *buf = (char *)malloc(size*sizeof(char));

    int bytes_read = read(STDIN_FILENO, buf, size*sizeof(char));
    if (bytes_read == -1)
    {
        perror("read");
        exit(1);
    }
    while (bytes_read != 0)
    {
        int bytes_written = write(STDOUT_FILENO, buf, bytes_read);
        if (bytes_written == -1)
        {
            perror("write");
            exit(1);
        }
        if (bytes_written != bytes_read)
        {
            printf("write issue!");
            exit(1);
        }

        bytes_read = read(STDIN_FILENO, buf, size*sizeof(char));
        if (bytes_read == -1)
        {
            perror("read");
            exit(1);
        }
    }

    free(buf);

    return 0;
}
