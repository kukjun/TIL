#include <stdio.h>

struct vector {
    double x;
    double y;
}; // 벡터인 구조체를 정의

struct vector get_vector_sum ( struct vector a,struct vector b); // 구조체가 함수원형에서 사용되므로 구조체를 먼저 정의하였다.

int main(void)
{
    struct vector A = { 2.0, 3.0};
    struct vector B = { 5.0, 6.0};
    struct vector sum;

    sum = get_vector_sum(A, B);
    printf("sum of vector = (%lf, %lf)\n", sum.x, sum.y);

    return 0;
}

struct vector get_vector_sum(struct vector a, struct vector b)
{
    struct vector result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}