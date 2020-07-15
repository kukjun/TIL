//
// Created by kukjun0712 on 2020-05-19.
//
#define SIZE 10
#include <stdio.h>

void array_copy(int *A, int *B, int size);

int main(void)
{
    int A[SIZE] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int B[SIZE] = { 0 };
    int i;
    array_copy(A, B, SIZE);
    for(i=0 ; i<SIZE ; i++)
        printf("B[%d] = %d, ", i, B[i]);
}

void array_copy(int *A, int *B, int size)
{
    int i;
    for(i=0 ; i<size ; i++) {
        *B = *A;
        B++;
        A++;
    }
}