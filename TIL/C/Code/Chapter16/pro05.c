#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    float Kor, Mat, Eng;
};

int main(void) {
    FILE *fp1, *fp2;
    char buffer[30];
        struct student s[10];
    struct student *p;
    p = s;
    float avrg, total;


    if ((fp1 = fopen("pro05.txt", "r")) == NULL)  // pro05.txt 파일을 연다.
    {
        fprintf(stderr, "we can not open file of grade 'pro05.txt'.\n");
        exit(1);
    }
    if ((fp2 = fopen("pro05_average.txt", "w")) == NULL) // pro05_average.txt 파일을 연다.
    {
        fprintf(stderr, "we can not open file of grade 'pro05_average.txt'.\n");
        exit(1);
    }

    // 저장된 값들을 더해 평균을 구하고 쓰기파일에 쓴다.
    while( !feof(fp1) )
    {
        fscanf(fp1, "%s %d %d %d", p->name, p->Kor, p->Mat, p->Eng);
        total = p->Kor + p->Mat + p->Eng;
        avrg = total / 3;
        p++;
        fprintf(fp2, "%f\n", avrg);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}