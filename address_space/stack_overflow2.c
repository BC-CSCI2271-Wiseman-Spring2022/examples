#include <stdio.h>

int global_i = 0;
int main()
{
    int i;
    printf("global_i=%i, &i=%p\n", global_i, &i);
    ++global_i;
    main();
    return 0;
}
