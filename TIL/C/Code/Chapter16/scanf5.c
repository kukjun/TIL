#include <stdio.h>
int main(void)
{
    int x, y, z;
    if (scanf("%d%d%d", &x, &y, &z) == 3)
        printf("sum of integer %d\n", x+y+z);
    else
        printf("saved answer isn't correct.\n");
    return 0;
}