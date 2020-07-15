#include <stdio.h>
#include <stdlib.h>

struct student {
    int number;
    char name[10];
    double grade;
};

int main(void)
{
    struct student s;

    s.number = 20070001;
    strcpy(s.name, "Hong Gil Dong");
    s.grade = 4.3;

    printf("number : %d\n", s.number);
    printf("name : %s\n", s.name);
    printf("grade : %f\n", s.grade);

    return 0;
}