#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open failed for test.txt");
        exit(1);
    }

    printf("Got file descriptor %i\n", fd);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }
    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}
