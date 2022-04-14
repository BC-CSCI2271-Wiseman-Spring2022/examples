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
    int fd = open("test", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    // dup fd onto stdin, so reading from stdin 
    // actually reads from fd instead
    if (dup2(fd, STDIN_FILENO) == -1)
    {
        perror("dup2");
        exit(1);
    }

    // we can close fd now because stdin is 
    // a duplicate of it
    close(fd);

    int c = fgetc(stdin);
    while(c != EOF)
    {
        fputc(c, stdout);
        c = fgetc(stdin);
    }

    return 0;
}

