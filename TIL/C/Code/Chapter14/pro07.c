#include <stdio.h>
#define HEIGHT 5
#define WIDTH 10

void binarize(int e[][WIDTH], int x);
void reverse(int e[][WIDTH]);

int image[HEIGHT][WIDTH] = {
        {0,0,0,0,9,0,0,0,0,0},
        {0,0,0,9,9,0,0,0,0,0},
        {0,0,9,0,9,0,0,0,0,0},
        {0,0,0,0,8,0,0,0,0,0},
        {0,0,0,0,9,0,0,0,0,0}
};

int main(void)
{
    int a, count, ch = 0;
    int *p, *endp;

    p = &image[0][0];
    endp = &image[HEIGHT-1][WIDTH-1];

    while(p <= endp) {
        printf("%d ", *p);
        p++;
        count++;
        if (count % 10 == 0)
            printf("\n");
    }

    printf("\n\ninput number(1 - a, 2 - b) : ");
    scanf("%d", &ch);

    if(ch == 1) {
        binarize(image, 10);
        p = &image[0][0];
        while (p <= endp) {
            printf("%d ", *p);
            p++;
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
    else if(ch == 2)
    {
        reverse(image);
        p = &image[0][0];
        while (p <= endp) {
            printf("%d ", *p);
            p++;
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }
    return 0;
}


void binarize(int e[][WIDTH], int x)
{
    int *p, *temp, *endp;
    p = &e[0][0];
    endp = &e[HEIGHT-1][WIDTH-1];
    while(p <= endp)
    {
        if(*p < x)
            *p++ = 0;
        else if(*p > x)
            *p++ = 255;
        else
            p++;
    }
}

void reverse(int e[][WIDTH])
{
    int *p, *endp;
    p = &e[0][0];
    endp = &e[HEIGHT-1][WIDTH-1];
    while(p <= endp)
    {
        *p = 255 - *p;
        p++;
    }
}