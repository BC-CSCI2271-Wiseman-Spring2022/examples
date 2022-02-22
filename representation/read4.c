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

    unsigned char c[4];

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    if (read(fd, &c, 4*sizeof(unsigned char)) < 4*sizeof(unsigned char))
    {
        perror("read");
        exit(1);
    }

    unsigned int i = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
    printf("%x\n", i);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}

