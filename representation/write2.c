#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s output_file\n", argv[0]);
        exit(1);
    }

    int i = 4276803;
    char c = 'A';

    int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    if (write(fd, &i, sizeof(int)) < sizeof(int))
    {
        perror("write");
        exit(1);
    }
    if (write(fd, &c, sizeof(char)) < sizeof(char))
    {
        perror("write");
        exit(1);
    }

    c = '\n';
    if (write(fd, &c, sizeof(char)) < sizeof(char))
    {
        perror("write");
        exit(1);
    }

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}

