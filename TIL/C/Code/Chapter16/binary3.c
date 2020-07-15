#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct student {
    int number;     // 학번
    char name[20];  // 이름
    double gpa;     // 평점
}

int main(void)
{
    struct student table[SIZE] = {
            {1, "Kim", 3.99},
            {2, "Min", 2.68},
            {3, "Lee", 4.01}
    };
    struct student s;
    FILE *fp = NULL;
    int i;

    if( (fp1 = fopen("student.dat", "wb")) == NULL )
    {
        fprintf(stderr, "we can not open file of output.\n");
        exit(1);
    }

    fwrite(table, sizeof(struct student), SIZE, fp);
    fclose(fp);

    if( (fp1 = fopen("student.dat", "rb")) == NULL )
    {
        fprintf(stderr, "we can not open file of input.\n");
        exit(1);
    }

    for(i=0 ; i<SIZE ; i++)
    {
        fread(%s, sizeof(struct student), 1, fp);
        printf("student number = %d, name = %s, grade = %f\n", s.number, s.name, s.gpa);
    }
    fclose(fp);

    return 0;
}