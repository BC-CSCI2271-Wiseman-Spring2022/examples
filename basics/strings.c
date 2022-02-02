#include <stdio.h>
#include <string.h>

int main() 
{
    char name[] = "Mario";

    name[5] = 'M';

    int length = strlen(name);

    printf("%s: %i\n", name, length);

    return 0;
}
