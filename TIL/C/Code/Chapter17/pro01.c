// 동적 메모리 할당을 이용하여 사용자로부터 양의 정수들의 합을 구하는 프로그램
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list;
    int count;
    int i;
    int sum = 0;

    printf("정수의 개수 : ");
    scanf("%d", &count);

    list = (int *)malloc( count * sizeof(int) );

    for(i=0 ; i<count ; i++)
    {
        printf("양의 정수를 입력하시오 : ");
        scanf("%d", &list[i]);
        sum += list[i];
    }

    printf("합은 %d 입니다.", sum);

    free(list);
    return 0;
}