#include <stdio.h>

struct complex {
    double real;
    double imag;
};
struct complex complex_add(struct complex c1, struct complex c2);

int main(void)
{
    struct complex a, b;
    struct complex result;
    printf("first number (re, im) :");
    scanf("%lf %lf", &a.real, &a.imag);

    printf("input second number (re, im) : ");
    scanf("%lf %lf", &b.real, &b.imag);

    result = complex_add(a, b);

    printf("result = %.3lf %.3lfi\n", result.real, result.imag);

    return 0;
}

struct complex complex_add(struct complex c1, struct complex c2)
{
    struct complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}