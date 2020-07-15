#include <stdio.h>

int main(void)
{

    int a = 10;
    int b = 20;
    int tmp;
    printf("%d %d\n", a, b);
    tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n", a, b);
    return 0;
}
