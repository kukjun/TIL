#include <stdio.h>

int main(void)
{
    int m[2][2] = { 1, 0, 2, 3 };

    printf("%u %u %u\n", &m[0][0], m[0], m);
    printf("%d %d", m[0][0], *(*(m+1)+1));

    return 0;
}