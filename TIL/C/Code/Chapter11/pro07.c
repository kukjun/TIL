//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void array_add(int *A, int *B, int *C, int size);
int main(void)
{
    int i;
    int A[SIZE], B[SIZE], C[SIZE];
    srand((unsigned)time(NULL));

    for(i=0 ; i<SIZE ; i++){
        A[i] = 200 + rand()%100;
    }
    for(i=0 ; i<SIZE ; i++){
        B[i] = rand()%30;
    }
    array_add(A, B, C, SIZE);
    printf("C[10] = { ");
    for(i=0 ; i<SIZE ; i++)
        printf("%d ", C[i]);
    printf("}\n");

    return 0;
}


void array_add(int *A, int *B, int *C, int size)
{
    int i;
    for(i=0 ; i<size ; i++){
        *C = *B + *A;
        A++;
        B++;
        C++;
    }
}