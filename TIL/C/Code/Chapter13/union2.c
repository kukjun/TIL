#include <stdio.h>
#include <string.h>

#define STU_NUMBER 1
#define REG_NUMBER 2

struct student {
    int type;
    union {
        int stu_number; // 학번
        char reg_number[15]; // 주민번호
    } id;
    char name[20];
};

void print(struct student s)
{
    switch (s.type)
    {
        case STU_NUMBER:
            printf("student_number : %d\n", s.id.stu_number);
            printf("studnet_name :%s\n", s.name);
            break;
        case REG_NUMBER:
            printf("regist : %s\n", s.id.reg_number);
            printf("studnet_name :%s\n", s.name);
            break;
        default:
            printf("type error\n");
            break;
    }
}

int main(void)
{
    struct student s1, s2;

    s1.type = STU_NUMBER;
    s1.id.stu_number = 20070001;
    strcpy(s1.name, "honggildong");

    s2.type = REG_NUMBER;
    strcpy(s2.id.reg_number, "860101-1056076");
    strcpy(s2.name, "kimchelsu");

    print(s1);
    print(s2);
}