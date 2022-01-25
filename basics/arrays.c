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

    for (int i=0; i<5; ++i)
    {
        printf("%i\n", nums[i]);
    }

    return 0;
}
