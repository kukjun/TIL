#include <stdio.h>

int main(void)
{
    char buffer[8];
    double *pd;
    int *pi;

    pd = (double *)buffer;
    *pd = 3.14;
    printf("%lf\n", *pd);

    pi = (int *)buffer;
    *pi = 123;
    *(pi+1) = 456;
    printf("%d %d\n", *pi, *(pi+1));

    return 0;
}