#include <stdio.h>

int main()
{
    // declare and allocate space for an array of 5 ints
    int nums[5];

    nums[0] = 100;
    nums[1] = -143;
    nums[2] = 0;
    nums[3] = 123456;
    nums[4] = -7;

    for (int i=-10; i<10; ++i)
    {
        printf("nums[%i] = %i\n", i, nums[i]);
    }

    return 0;
}
