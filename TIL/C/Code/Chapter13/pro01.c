#include <stdio.h>

struct point {
    int x, y;
};

int equal (struct point p1, struct point p2);
int quadrant(struct point p);

int main(void)
{
    struct point a, b, c;
    a.x = 5;
    a.y = 10;
    b.x = 5;
    b.y = 10;
    printf("%d\n", equal(a, b));

    printf("%d\n", quadrant(c));
}

int equal (struct point p1, struct point p2)
{
    if(p1.x == p2.x)
    {
        if(p1.y == p1.y)
            return 1;
    }
    else
        return 0;
}

int quadrant(struct point p)
{
    printf("input two spot (x, y):");
    scanf("%d %d", &p.x, &p.y);
    if(p.x>0 && p.y>0)
        return 1;
    else if(p.x<0 && p.y>0)
        return 2;
    else if(p.x<0 && p.y<0)
        return 3;
    else if(p.x>0 && p.y<0)
        return 4;
    else
        return 0;
}