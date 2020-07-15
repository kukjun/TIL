//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd);

int main(void)
{
    int x, y;
    int lcm, gcd;

    printf("input two word :");
    scanf("%d %d", &x, &y);

    get_lcm_gcd(x, y, &lcm, &gcd);

    printf("lcm = %d, gcd = %d\n", lcm, gcd);

    return 0;
}

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd)
{
    int r, a, b;
    a = x;
    b = y;
    while ( y != 0 )
    {
        r = x % y;
        x = y;
        y = r;
    }
    *p_gcd = x;
    *p_lcm = (a * b) / *p_gcd;
}