#include <stdio.h>
#include <string.h>

int main() 
{
    char s[3];

    s[0] = 'a';
    s[1] = '\0';
    s[2] = 'c';

    int length = strlen(s);

    printf("%s: %i\n", s, length);

    return 0;
}
