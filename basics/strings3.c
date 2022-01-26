#include <stdio.h>

int main() 
{
    char s[] = "hello there";
    char t[] = "and goodbye";

    // replace the null character ending s with a comma
    s[11] = ',';

    printf("%s\n", s);

    return 0;
}
