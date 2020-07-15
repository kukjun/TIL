#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct student {
    int number;
    char name[20];
    double grade;
    struct date *dob;
};

int main(void)
{
    struct date d = { 3, 20, 1980 };
    struct student s = { 20070001, "Kim", 4.3};

    s.dob = &d;

    printf("number : %d\n", s.number);
    printf("name : %s\n", s.name);
    printf("grade : %lf\n", s.grade);
    printf("birth day : %d year, %d month, %d day\n", s.dob->year, s.dob->month, s.dob->day);

    return 0;
}