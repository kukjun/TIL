#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 50

typedef struct NODE {
    char title[S_SIZE];
    int year;
    struct NODE *link;
} NODE;

int main(void)
{
    NODE *list = NULL;
    NODE *prev, *p, *next;
    char buffer[S_SIZE];
    int year;

    // 연결리스트에 정보를 입력한다.
    while(1) {
        printf("책의 제목을 입력하세요 : (종료하려면 엔터) ");
        gets(buffer);
        if (buffer[0] == '\0')
            break;
        p = (NODE *) malloc(sizeof(NODE));
        strcpy(p->title, buffer);
        printf("책의 출판연도를 입력하세요. : ");
        gets(buffer);
        year = atoi(buffer);
        p->year = year;

        if (list == NULL)       // 리스트가 비어 있으면
            list = p;           // 새로운 노드를 첫번째 노드로 만든다.
        else                    // 리스트가 비어 있으면
            prev->link = p;     // 새로운 노드를 이전 노드의 끝에 붙인다.
        p->link = NULL;         // 새로운 노드의 링크 필드를 NULL로 설정
        prev = p;
    }
    printf("\n");

    // 연결 리스트에 들어 있는 정보를 모두 출력한다.
    p = list; // 헤드포인터 찾기
    while( p != NULL) // 반복하다가 마지막 p->link를 만나면 종료
    {
        printf("책의 제목 :%s, 출판 연도 :%d \n", p->title, p->year);
        // p를 통해 첫번째 노드가 가진 정보를 출력
        p = p->link; // p가 두번째 노드를 가리키도록 한다.
    }

    // 동적 할당을 반납한다.
    p = list; // 헤드포인터 찾기
    while(p != NULL) // 반복하다가 마지막 p->link를 만나면 종료
    {
        next = p->link; // p가 가리키는 공간을 반납하면 p->list를
        // 참조할 수 없으므로, 반납하기 전에 p->list를 next에 저장한다.
        free(p); // 메모리 공간 반납
        p = next; // 다음 연결리스트 노드의 위치를 가지는 next를 p에 대입해서 반복
    }

    return 0;
}