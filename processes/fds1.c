#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int fd1 = open("test", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd1 == -1)
    {
        perror("open");
        exit(1);
    }

    int fd2 = open("test", O_WRONLY);
    if (fd2 == -1)
    {
        perror("open");
        exit(1);
    }

    char s1[] = "Optimus\n";
    char s2[] = "Prime\n";

    write(fd1, s1, strlen(s1));
    write(fd2, s2, strlen(s2));

    close(fd1);
    close(fd2);
    return 0;
}

