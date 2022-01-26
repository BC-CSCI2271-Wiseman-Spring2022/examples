#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: range start stop\n");
        return 0;
    }

    int start = atoi(argv[1]);
    int stop = atoi(argv[2]);

    if (start <= stop)
    {
        for (int i=start; i<=stop; ++i)
        {
            printf("%i\n", i);
        }
    }
    else 
    {
        for (int i=start; i>=stop; --i)
        {
            printf("%i\n", i);
        }
    }

    return 0;
}
