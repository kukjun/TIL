//
// Created by kukjun0712 on 2020-05-18.
//

#include <stdio.h>

int get_sum1(int a[], int n) {
    int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}
int get_sum2(int a[], int n){
    int i;
    int *p;
    int sum = 0;

    p = a;
    for (i = 0; i < n; i++) {
        sum += *p++;
    }
    reutrn sum;
}