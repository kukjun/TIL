#include <stdio.h>

void merge(int *A, int *B, int *C, int size);

int main(void)
{
    int A[]={ 2, 5, 7, 8};
    int B[]={ 1, 3, 4, 6};
    int C[8] = {0};
    int size = sizeof(C)/sizeof(C[0]);
    int i, countA, countB;

    merge(A, B, C, size);

    printf("C[8] = { ");
    for(i=0 ; i<size ; i++)
        printf("%d ", C[i]);
    printf("}\n");

    return 0;
}

void merge(int *A, int *B, int *C, int size)
{
    int i;
    int countA, countB;
    for(i=0, countA=0, countB=0 ; i<size ; i++)
    {
        if(*A<*B){
            if(countA < 4) {
                *C++ = *A++;
                countA++;
            }
            else
                *C++ = *B++;
        }
        else
            if(countB < 4) {
                *C++ = *B++;
                countB++;
            }
            else
                *C++ = *A++;
    }
}