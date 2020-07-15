#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    char name[100];
    char phone[100];
    struct NODE *link;
} NODE;

int main(void)
{
    NODE *list = NULL;
    NODE *prev, *p, *next;
    int number;
    while(1)
    {
        printf("연결 리스트를 이용한 전화 번호부 메뉴\n");
        printf("--------------------------------\n");
        printf("1. 초기화\n2. 전화 번호 추가\n3. 전화 번호 탐색\n4. 종료\n");
        printf("--------------------------------\n");
        printf("번호를 입력하세요 :");
        fflush(stdin);
        scanf( "%d", &number);

        if(number == 1) // 초기화 = 동적할당을 반납한다.
        {
            p = list; // 헤드포인터 찾기
            while(p != NULL) // 반복하다가 마지막 p->link를 만나면 종료
            {
                next = p->link; // p가 가리키는 공간을 반납하면 p->list를 참조할 수
                // 없으므로, 반납하기 전에 p->list를 next에 저장한다.
                free(p); // 메모리 공간 반납
                p = next; // 다음 연결리스트 노드의 위치를 가지는 next를 p에 대입해서 반복
                list = NULL;
            }
            printf("초기화 되었습니다.\n");
        }
        else if(number == 2) // 전화 번호 추가 = 동적 할당 시작
        {
            p = (NODE *) malloc(sizeof(NODE));
            printf("이름 : ");
            scanf("%s", p->name);
            printf("휴대폰 번호 : ");
            scanf("%s", p->phone);

            if(list == NULL)
                list = p;
            else
                prev->link = p;
            p->link = NULL;
            prev = p;
            printf("추가되었습니다.\n");
        }
        else if(number == 3) // 전화 번호 탐색 = 출력
        {
            printf("===========================================\n");
            printf("-------------------------------------------\n");
            p = list; // 헤드포인터 찾기
            while( p != NULL) // 반복하다가 마지막 p->link를 만나면 종료
            {
                printf("이름 :%s\n 전화번호 :%s\n", p->name, p->phone);
                // p를 통해 첫번째 노드가 가진 정보를 출력
                p = p->link; // p가 두번째 노드를 기리키도록 한다.
                printf("-------------------------------------------\n");
            }
        }
        else if(number == 4) // 종료 = 반환하고 종료
        {
            p = list; // 헤드포인터 찾기
            while(p != NULL) // 반복하다가 마지막 p->link를 만나면 종료
            {
                next = p->link; // p가 가리키는 공간을 반납하면 p->list를 참조할 수
                // 없으므로, 반납하기 전에 p->list를 next에 저장한다.
                free(p); // 메모리 공간 반납
                p = next; // 다음 연결리스트 노드의 위치를 가지는 next를 p에 대입해서 반복
            }
            break;
        }
        else
            printf("잘못입력하셨습니다. 다시 하세요.\n");
    }
    return 0;
}