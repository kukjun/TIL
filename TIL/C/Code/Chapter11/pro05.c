//
// Created by kukjun0712 on 2020-05-19.
//

#include <stdio.h>

void convert(double *grades, double *scores, int size);

int main(void) {
    int i;
    double grade[10] = {4.3, 2.3, 1.2, 4.2, 2.7, 3.9, 4.1, 4.0, 1.1, 1.9};
    double score[10] = {0};
    int size = sizeof(grade) / sizeof(grade[0]);
    convert(grade, score, size);

    printf("score[10] = { ");
    for (i = 0; i < 10; i++) {
        printf(" %.3lf", score[i]);
    }
    return 0;
}

void convert(double *grades, double *scores, int size)
{
    int i;
    for(i=0 ; i<size ; i++){
        *scores = *grades * 100.0/4.3;
        scores++;
        grades++;
    }
}