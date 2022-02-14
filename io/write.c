#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("output.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open failed for output.txt");
        exit(1);
    }

    char msg[] = "These are not the droids you're looking for...\n";
    int size = write(fd, msg, strlen(msg));
    if (size < 0)
    {
        perror("write");
        exit(1);
    }
    printf("Wrote %i bytes: %s", size, msg);

    int value = 421;
    size = write(fd, &value, sizeof(int));
    if (size < 0)
    {
        perror("write");
        exit(1);
    }
    printf("Wrote %i bytes: %i\n", size, value);

    if (close(fd) < 0)
    {
        perror("close");
        exit(1);
    }

    return 0;
}
