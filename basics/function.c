#include <stdio.h>
#include <stdlib.h>

void print_range(int start, int stop);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: range start stop\n");
        return 0;
    }

    print_range(atoi(argv[1]), atoi(argv[2]));
    
    return 0;
}

void print_range(int start, int stop)
{
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
}
