#include <stdio.h>

#define A 3 // ROW
#define B 3 // COLUMN

int get_sum(int array[], int size);

int main(void)
{
    int a[A][B] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int i, totalsum = 0;
    int size_A, size_B;

    size_A = sizeof(a)/sizeof(a[0]); // 필요 X
    size_B = sizeof(a[0])/sizeof(a[0][0]);

    for(i=0 ; i<size_A ; i++)
        totalsum += get_sum(a[i], size_B);
    printf("total sum = %d", totalsum);
    return 0;
}

int get_sum(int array[], int size)
{
    int *p;
    int i;
    int sum = 0;

    p = &array[0];

    for(i=0 ; i<size ; i++)
        sum += *(p++);
    return sum;
}