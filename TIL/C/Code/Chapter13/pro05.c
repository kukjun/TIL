#include <stdio.h>

struct vector {
    double x;
    double y;
};

struct vector vector_add( struct vector v1,struct vector v2);

int main(void)
{
    struct vector v1, v2, rv;

    printf("input v1 (x, y) :");
    scanf("%lf %lf", &v1.x, &v1.y);

    printf("input v2 (x, y) : ");
    scanf("%lf %lf", &v2.x, &v2.y);

    rv = vector_add(v1, v2);

    printf("result v = (%.2lf %.2lf)\n", rv.x, rv.y);

    return 0;
}
struct vector vector_add(struct vector v1,struct vector v2)
{
    struct vector V;
    V.x = v1.x + v2.x;
    V.y = v1.y + v2.y;

    return V;
}