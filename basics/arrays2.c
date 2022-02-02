#include <stdio.h>

int main()
{
    // declare and allocate space for an array of 5 ints
    char nums[5];

    nums[0] = 'a';
    nums[1] = 'b';
    nums[2] = 'c';
    nums[3] = 'd';
    nums[4] = 'e';

    for (int i=-10; i<10; ++i)
    {
        printf("nums[%i] = %c\n", i, nums[i]);
    }

    return 0;
}
