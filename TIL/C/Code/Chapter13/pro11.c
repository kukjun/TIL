#include <stdio.h>

enum figure { Triangle, Rect, Circle };

struct shape {
    int type;
    union {
        struct { int base, height } tri;
        struct { int width, height } rect;
        struct { int radius } circ;
    } data;
};

int main(void)
{
    struct shape mine;
    enum figure F;

    printf("input type : ");
    scanf("%d", mine.type);
}