#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
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

    if (fork_rv == 0)
    {
        // in the child process

        // open the file test for reading
        int read_fd = open("test", O_RDONLY);
        if (read_fd == -1)
        {
            perror("open");
            exit(1);
        }

        // dup read_fd onto stdin
        if (dup2(read_fd, STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(read_fd);

        // open the file test.out for writing
        int write_fd = open("test.out", O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if (write_fd == -1)
        {
            perror("open");
            exit(1);
        }

        // dup write_fd onto stdout
        if (dup2(write_fd, STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(write_fd);

        // now, execute cat normally
        char *args[2];
        args[0] = "cat";
        args[1] =  NULL;
        execvp(args[0], args);

        // will never get here if things work correctly
        perror("execvp");
        exit(1);
    }

    // in the parent
    
    // wait on the child to exit
    if (waitpid(fork_rv, NULL, 0) == -1)
    {
        perror("waitpid");
        exit(1);
    }

    return 0;
}
