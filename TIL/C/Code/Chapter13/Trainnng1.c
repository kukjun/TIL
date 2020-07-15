#include <stdio.h>

struct student {
    char name[20];
    int number;
    double grade;
};
struct student list[] = {
          {"HongGilDong", 20120001, 4.2 },
          {"GimChelSu", 20120002, 3.2 },
          {"KimYungHi", 20120003, 3.9}
};

int main(void)
{
    struct student super_stu;
    int i, size;

    size = sizeof(list)/sizeof(list[0]);

    super_stu = list[0];
    for(i=1 ; i<size ; i++){
        if(list[i].grade > super_stu.grade)
            super_stu = list[i];
    }
    printf("the most greatest student (name:%s, number:%d, grade:%lf)\n",
             super_stu.name, super_stu.number, super_stu.grade);
}