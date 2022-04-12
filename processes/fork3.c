#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    char local_char = 'P';
    char *dyn_char = (char *)malloc(sizeof(char));
    *dyn_char = '1';

    int fd = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }

    if (fork_rv != 0)
    {
        // in the parent
        sleep(5);
    }
    else
    {
        // in the child
        local_char = 'C';
        *dyn_char = '2';
    }

    // both parent and child run this code

    if (write(fd, &local_char, sizeof(char)) != sizeof(char))
    {
        perror("write");
    }
    if (write(fd, dyn_char, sizeof(char)) != sizeof(char))
    {
        perror("write");
    }

    local_char = '\n';
    if (write(fd, &local_char, sizeof(char)) != sizeof(char))
    {
        perror("write");
    }

    return 0;
}

