#include <stdio.h>

struct student {
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student s;

    printf("input number :");
    scanf("%d", &s.number);

    printf("input name :");
    scanf("%s", &s.name);

    printf("input grade :");
    scanf("%lf", &s.grade);

    printf("number : %d\nname : %s\ngrade : %lf\n", s.number, s.name, s.grade);
    return 0;
}