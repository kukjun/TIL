#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *link;
} NODE;

int main(void)
{
    NODE *list = NULL;
    NODE *prev, *p, *next;
    int data;

    while(1) // 연결리스트 정보 입력
    {
        printf("양의 정수를 입력하세요(종료:-1): ");
        scanf("%d", &data);
        if(data == -1)
            break;
        p = (NODE *)malloc(sizeof(NODE));
        p->data = data;

        if(list == NULL)
            list = p;
        else
            prev->link = p;
        p->link = NULL;
        prev = p;
    }

    p = list; // 연결리스트 정보 출력
    while(p != NULL)
    {
        printf("%d",p->data);
        p = p->link; // p가 두 번째 노드를 가리킨다.
        if(p != NULL)
            printf("->");
        else
            printf("->NULL");
    }

    p = list; // 동적 할당 반납
    while(p != NULL)
    {
        next = p->link;
        free(p);
        p = next;
    }

    return 0;
}