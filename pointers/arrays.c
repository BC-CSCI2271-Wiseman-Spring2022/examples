#include <stdio.h>

int main()
{
    int vals[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    printf("vals=%p\n", vals);
    printf("&vals=%p\n\n", &vals);

    for (int i=0; i<8; ++i)
    {
        printf("&vals[%i]=%p\n", i, &vals[i]);
    }

    return 0;
}
