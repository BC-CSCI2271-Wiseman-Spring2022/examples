#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t my_pid = getpid();
    pid_t parent_pid = getppid();

    printf("my pid=%u\n", my_pid);
    printf("parent pid=%u\n", parent_pid);

    return 0;
}
