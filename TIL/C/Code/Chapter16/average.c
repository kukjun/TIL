#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char fname[100];
    int number, count = 0;
    char name[20];
    float score, total = 0.0;

    printf("input file name of grade : ");
    scanf("%s", fname);

    if ((fp = fopen(fname, "w")) == NULL) {
        fprintf(stderr, "we can not open file of grade '%s'.\n", fname);
        exit(1);
    }

    // 사용자로부터 학번, 이름, 성적을 받아서 파일에 저장한다.
    while (1) {
        printf("input student number, name, grade : (exit = -1) ");
        scanf("%d", &number);
        if (number < 0) break;
        scanf("%s %f", name, &score);
        fprintf(fp, "%d %s %f\n", number, name, score);
    }
    fclose(fp);

    // 성적파일을 읽기 모드로 연다.
    if( (fp = fopen(fname, "r")) == NULL )
    {
        fprintf(stderr, "we can not open file of grade '%s'.\n", fname);
        exit(1);
    }

    // 파일에서 성적을 읽어서 평균을 구한다.
    while( !feof(fp) )
    {
        fscanf(fp, "%d %s %f", &number, name, &score);
        total += score;
        count++;
    }

    printf("average : %f\n", total/count);
    fclose(fp);

    return 0;
}