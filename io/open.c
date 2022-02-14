#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open failed for test.txt");
        exit(1);
    }

    printf("Got file descriptor %i\n", fd);
    return 0;
}
