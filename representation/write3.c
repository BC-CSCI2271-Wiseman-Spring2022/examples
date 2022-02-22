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

    /* could also use 0x61626364 */
    unsigned int i = 1633837924; 

    int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    /* should really used uint8_t here */
    unsigned char c[4];
    c[0] = (i & 0xff000000) >> 24;
    c[1] = (i & 0x00ff0000) >> 16;
    c[2] = (i & 0x0000ff00) >> 8;
    c[3] = (i & 0x000000ff);

    if (write(fd, &c, 4*sizeof(unsigned char)) < 4*sizeof(unsigned char))
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

