// 다차원 배열과 포인터
#include <stdio.h>

int main(void)
{
    int m[3][3] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    printf("m = %u\n", m);
    printf("m[0] = %u\n", m[0]);
    printf("m[1] = %u\n", m[1]);
    printf("m[2] = %u\n", m[2]);
    printf("m[0][0] = %u\n", &m[0][0]);
    printf("m[1][0] = %u\n", &m[1][0]);
    printf("m[2][0] = %u\n", & m[2][0]);

    return 0;
}