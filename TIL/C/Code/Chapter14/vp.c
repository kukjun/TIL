#include <stdio.h>

int main(void)
{
    int a[] = { 10, 20, 30, 40, 50 };
    void *vp;

    vp = &a;
    vp = &a[2];

    // *vp = 35;    *연산자는 혼자 사용할 수 없다.
    // vp++;    증감연산자는 사용할 수 없다.

    *(int *)vp = 35;

    return 0;
}