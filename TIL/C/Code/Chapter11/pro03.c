//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void array_fill(int *A, int size);

int main(void)
{
    int A[SIZE]={0};
    int size, i;

    srand((unsigned)time(NULL));
    size = sizeof(A)/sizeof(A[0]);

    array_fill(A, size);

    for(i=0 ; i<SIZE ; i++)
        printf("A[%d] = %d\n", i, A[i]);

    return 0;
}
void array_fill(int *A, int size)
{
    int i;
    for(i=0 ; i<size ; i++) {
        *A = rand() % 100;
        A++;
    }
}