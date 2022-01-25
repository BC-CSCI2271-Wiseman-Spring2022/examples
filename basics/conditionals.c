#include <stdio.h>

int main()
{
    int some_value = 7;

    if (some_value > 0) 
    {
        printf("It's positive!\n");
    } 
    else if (some_value == 0)
    {
        printf("It's zero!\n");
    } 
    else
    {
        printf("It's negative!\n");
    }

    return 0;
}
