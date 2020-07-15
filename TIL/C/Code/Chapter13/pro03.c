#include <stdio.h>

struct point {
    double x, y;
};

struct rectangle {
    struct point a, b;
};

int area(struct rectangle r);
int perimeter(struct rectangle r);
int is_square(struct rectangle r);

int main(void)
{
    struct rectangle spot;
    double AREA, PERIMETER, square;
    printf("input right upside : ");
    scanf("%lf %lf", &spot.a.x, &spot.a.y);

    printf("input lift downside : ");
    scanf("%lf %lf", &spot.b.x, &spot.b.y);

    AREA = area(spot);
    PERIMETER = perimeter(spot);
    square = is_square(spot);

    printf("area : %lf\nperimeter : %lf\n", AREA, PERIMETER);

    if(square == 0)
        printf("square\n");
    else
        printf("not square\n");

    return 0;
}

int area(struct rectangle r)
{
    return (r.a.x - r.b.x) * (r.a.y - r.b.y);
}

int perimeter(struct rectangle r)
{
    return 2 * (r.a.x - r.b.x) + 2 * (r.a.y - r.b.y);
}

int is_square(struct rectangle r)
{
    if((r.a.x - r.b.x) == (r.a.y - r.b.y))
        return 0;
    else
        return 1;
}