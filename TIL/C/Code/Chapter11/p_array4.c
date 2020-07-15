//
// Created by kukjun0712 on 2020-05-18.
//

#include <stdio.h>

void print_reverse(int a[], int n);
int main(void)
{
    int a[] = { 10, 20, 30, 40, 50 };
    print_reverse(a, 5);
    return 0;
}
void print_reverse(int a[], int n)
{
    int *p = a + n - 1;
    while(p >= a)
        printf("%d\n", *p--);
}