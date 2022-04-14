#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    execlp("cat","cat","getpids.c", NULL);
    perror("execlp");
    return 0;
}
