#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char **A = NULL;
    int n;
    int i;

    printf("문자열의 개수 : ");
    scanf("%d", &n);

    if ( (A=malloc(n*sizeof(char)) ) != NULL)
    {
        for(i=0 ; i<n ; i++)
            A[i] = (char *)malloc(100);
        printf("%d개의 문자열을 저장할 수 있는 공간이 할당되었습니다.\n", n);
        for(i=n-1 ; i<-1 ; i--)
        {
            free(A[i]);
        }
        free(A);
    }
    return 0;
}