//
// Created by kukjun0712 on 2020-05-18.
//

#include <stdio.h>
void swap(int x, int y);

int main(void)
{
    int a = 100, b = 200;

    printf("a=%d b=%d\n", a, b);
    swap(a, b);
    printf("a=%d b=%d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int tmp;

    printf("x=%d y=%d", x, y);

    x= tmp;
    y= x;
    tmp= y;

    printf("x=%d y=%d", x, y);
}