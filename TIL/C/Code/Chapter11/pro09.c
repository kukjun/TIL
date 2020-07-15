//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>

int search(int *A, int size, int search_value);

int main(void) {
    int A[] = {100, 200, 300, 400, 500, 600, 700, 800};
    int size = sizeof(A)/sizeof(A[0]);
    int want_index;

    want_index = search(A, size, 200);

    printf("answer = A[%d]", want_index);

    return 0;
}

int search(int *A, int size, int search_value)
{
    int i;
    for(i=0 ; i<size ; i++)
    {
        if(A[i] == search_value)
            return A[i];
    }
}