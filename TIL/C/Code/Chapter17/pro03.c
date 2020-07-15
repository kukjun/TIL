#include <stdio.h>
#include <stdlib.h>

typedef struct Address{
    char name[100];
    char phone[100];
} ADDRESS;

int main(void)
{
    ADDRESS *addr;
    int count;
    int i;

    printf("주소의 개수 :" );
    scanf("%d", &count);

    addr = (ADDRESS *)malloc(sizeof(ADDRESS)*count);

    if(addr == NULL)
    {
        printf("메모리 할당 에러");
        exit(1);
    }

    for(i=0 ; i<count ; i++)
    {
        printf("이름을 입력하십시오 : ");
        fflush(stdin);
        scanf("%s", addr[i].name);
        printf("휴대폰 번호를 입력하십시오 : ");
        scanf("%s", addr[i].phone);
    }

    printf("=====================================\n");
    printf("이름 \t 휴대폰 번호\n");
    printf("=====================================\n");
    for(i=0 ; i < count ; i++)
    {
        printf("%s \t %s\n", addr[i].name, addr[i].phone);
        printf("=====================================\n");
    }
    free(addr);

    return 0;

}