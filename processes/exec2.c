#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    char *args[3];
    args[0] = "cat";
    args[1] = "getpids.c";
    args[2] =  NULL;
    execvp(args[0], args);
    perror("execvp");
    return 0;
}
