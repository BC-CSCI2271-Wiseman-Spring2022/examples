#include <stdio.h>
#include <ctype.h>

void do_something(char a[])
{
    printf("Workin' hard!\n");
    if(isdigit(a))
    {
        printf("boo\n");
    }
}

int main()
{
    char s[] = "42";

    do_something(s);

    return 0;
}
