#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("# of args: %i\n", argc);
    
    for (int i=0; i<argc; i++)
    {
        printf("Arg %i: %s\n", i, argv[i]);
    }
    
    return 0;
}
