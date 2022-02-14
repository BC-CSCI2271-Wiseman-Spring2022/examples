#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char c;
    while (read(STDIN_FILENO, &c, sizeof(char)) == 1)
    {
        if (write(STDOUT_FILENO, &c, sizeof(char)) != 1)
        {
            perror("write");
            exit(1);
        }
    }
            
    return 0;
}
