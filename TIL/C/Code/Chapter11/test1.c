//
// Created by kukjun0712 on 2020-05-18.
//

#include <stdio.h>
void blight(int light[][5]);
void test1(void)
{
    int light[5][5] = { 0 };
    int i, j, add = 10;
    int *p;

    p = light;

    for(i=0 ; i<5 ; i++)
    {

        for(j=0 ; j<5 ; j++)
        {
            *p += add;
            printf("%03d ", *p);
            *p++;
        }
        printf("\n");
    }
}

void blight(int light[][5])
{

}