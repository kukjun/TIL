#include <stdio.h>
#define SIZE 3

struct student {
    int number;
    char name[20];
    double grade;
};

int main(void)
{
    struct student list[SIZE];
    int i;

    for(i=0 ; i<SIZE ; i++)
    {
        printf("input number :");
        scanf("%d", &list[i].number);
        printf("input name :");
        scanf("%s", list[i].name);
        printf("input grade :");
        scanf("%lf", &list[i].grade);
    }

    for(i=0 ; i<SIZE ; i++)
        printf("name : %s, grade : %lf\n", list[i].name, list[i].grade);

    return 0;
}