//
// Created by kukjun0712 on 2020-05-18.
//
// 포인터와 배열의 관계
#include <stdio.h>
void p_array1(void);
int main(void)
{
    p_array1();
    return 0;
}

void p_array1(void)
{
    int a[] = { 10, 20, 30, 40, 50 };

    printf("&a[0] = %u\n", &a[0]);
    printf("&a[1] = %u\n", &a[1]);
    printf("&a[2] = %u\n", &a[2]);

    printf("a = %u\n", a);
}