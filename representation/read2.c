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
        printf("usage: %s input_file\n", argv[0]);
        exit(1);
    }

    int i;
    char c;

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    if (read(fd, &c, sizeof(char)) < sizeof(char))
    {
        perror("read");
        exit(1);
    }
    if (read(fd, &i, sizeof(int)) < sizeof(int))
    {
        perror("read");
        exit(1);
    }

    printf("%c,%i\n", c, i);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}

