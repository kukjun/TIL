//
// Created by kukjun0712 on 2020-05-18.
//

#include <stdio.h>

void get_sum_diff(int x, int y, int *p_sum,int *p_diff);

int main(void)
{
    int a, b;
    int sum = 0;
    int diff = 0;
    printf("input two number :");
    scanf("%d %d", &a, &b);

    get_sum_diff(a, b, &sum, &diff);

    printf("sum = %d, diff = %d", sum, diff);
    return 0;
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff)
{
    *p_sum = x + y;
    *p_diff = x - y;
}