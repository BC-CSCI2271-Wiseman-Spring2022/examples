#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main()
{
    int fd;
    fd = open("input.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed for input.txt");
        exit(1);
    }

    char buf[BUF_SIZE];

    int size = read(fd, buf, 29);
    if(size < 0)
    {
        perror("read");
        exit(1);
    }
    buf[size] = '\0';
    printf("Read %i bytes: %s", size, buf);

    int size2 = read(fd, buf, BUF_SIZE);
    if(size2 < 0)
    {
        perror("read");
        exit(1);
    }
    buf[size2] = '\0';
    printf("Read %i bytes: %s", size2, buf);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}
