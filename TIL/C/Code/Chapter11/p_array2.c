//
// Created by kukjun0712 on 2020-05-18.
//
#include <stdio.h>

void p_array2(void)
{
    int a[] = { 10, 20, 30, 40, 50 };

    printf("a = %u\n", a); // 배열의 이름을 포인터로 사용

    printf("a + 1 = %u\n", a + 1); // 배열의 이름 + 1은 배열[1]과 동일

    printf("*a = %d\n", *a);

    printf("*(a+1) = %d\n", *(a+1));
}