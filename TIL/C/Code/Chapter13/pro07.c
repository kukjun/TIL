#include <stdio.h>

struct food {
    char name[100];
    int calories;
};

int main (void)
{
    struct food food_array[3];
    int i;
    for(i=0 ; i<3 ; i++)
    {
        printf("input %d food name : ", i+1);
        scanf("%s", food_array[i].name);
        printf("input %d food calorie : ", i+1);
        scanf("%d", &food_array[i].calories);
    }
    printf("all food calories = %d", food_array[0].calories + food_array[1].calories + food_array[2].calories);

    return 0;
}