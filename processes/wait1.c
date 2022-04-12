#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    pid_t fork_rv = fork();
    if (fork_rv == -1)
    {
        perror("fork");
        exit(1);
    }

    if (fork_rv != 0)
    {
        // in the parent
        int status;
        pid_t wpid = wait(&status);
        if (wpid == -1)
        {
            perror("wait");
            exit(1);
        }
        printf("In parent, waited on pid %u, ", wpid);
        printf("child exited with: %d\n", WEXITSTATUS(status));
    }
    else
    {
        // in the child
        printf("In child, pid=%u, ", getpid());
        printf("exiting with status 3\n");
        return 3;
    }
    return 0;
}

