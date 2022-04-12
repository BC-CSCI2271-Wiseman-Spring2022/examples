#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    printf("My pid=%u\n", getpid());

    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }

    if (fork_rv != 0)
    {
        sleep(5);
    }

    printf("fork_rv=%u, pid=%u, ppid=%u\n", fork_rv, getpid(), getppid());

    return 0;
}

