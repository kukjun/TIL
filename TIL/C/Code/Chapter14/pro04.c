#include <stdio.h>

void set_max_ptr(int m[], int size, int **ppmax);

int main(void)
{
    int m[6] = { 5, 6, 1, 3, 7, 9};
    int *pmax;

    set_max_ptr(m, 6, &pmax);
    return 0;
}

void set_max_ptr(int m[], int size, int **ppmax)
{
    int i;
    *ppmax = &m[0];
    for(i=1 ; i<size ; i++)
    {
        if(m[i] > **ppmax)
            *ppmax = &m[i];
    }
    printf("max = %d", **ppmax);
}