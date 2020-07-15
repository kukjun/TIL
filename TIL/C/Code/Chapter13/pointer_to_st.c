#include <stdio.h>

struct student {
    int number;
    char name[20];
    double grade;
};

int main(void)
{
    struct student s = { 20070001, "honggildong", 4.3};
    struct student *p;

    p = &s;

    printf("number : %d, name : %s, grade : %lf\n", s.number, s.name, s.grade);
    printf("number : %d, name : %s, grade : %lf\n", (*p).number, (*p).name, (*p).grade);
    printf("number : %d, name : %s, grade : %lf\n", p->number, p->name, p->grade);

    return 0;
}