#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int i;
    for (i=0; i<10; ++i)
    {
        pid_t fork_rv = fork();
        if (fork_rv == -1)
        {
            perror("fork");
            exit(1);
        }

        if (fork_rv == 0)
        {
            // in the child
            break;
        }
    }
    if (i == 10)
    {
        // in the parent
        for(i=0; i<10; ++i)
        {
            pid_t wpid = wait(NULL);
            if (wpid == -1)
            {
                perror("wait");
                exit(1);
            }
            printf("In parent, waited on pid %u\n", wpid);
        }
    }
    else
    {
        // in a child
        printf("In child %i, pid=%u\n", i, getpid());
        sleep(1);
    }

    return 0;
}

