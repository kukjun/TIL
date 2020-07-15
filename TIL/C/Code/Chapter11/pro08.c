//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int array_sum(int *A, int size);

int main(void)
{
    int A[SIZE];
    int i, sum;

    srand((unsigned)time(NULL));

    for(i=0 ; i<SIZE ; i++)
        A[i] = rand()%300;
    sum = array_sum(A, SIZE);
    printf("sum = %d", sum);

    return 0;
}

int array_sum(int *A, int size)
{
    int i, sum =0;
    for(i=0 ; i<size ; i++){
        sum += *A;
        A++;
    }
    return sum;
}