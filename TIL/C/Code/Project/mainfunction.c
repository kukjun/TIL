#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct text{
    char word[20];
    char mean[20];
} TEXT;

void administer(void);
void user(void);

int main(void)
{
    int choice, passcount = 0;
    char id[10] = "kukjun";
    char inputid[10] = {0}; // 동적메모리사용
    char ps[10] = "kukkuk123";
    char inputps[10] = {0}; // 동적메모리사용

    printf("영어 단어장입니다.\n\n\n");
    while(1)
    {
        printf("관리자모드는 1번, 사용자 모드는 2번, 종료는 3번을 입력해주세요 :");
        scanf("%d", &choice); // switch
        fflush(stdin);
        if (choice == 1) // 관리자모드 구현
        {
            printf("관리자 모드로 선택하셨습니다.\n");
            printf("관리자 아이디와 비밀번호를 입력해주세요.\n"); // 로그인 구현
            printf("Id : ");
            scanf("%s", inputid); // 에코 없이 구현
            printf("Password : ");
            scanf("%s", inputps); // 에코 없이 구현 git 업로드
            if(strcmp(id, inputid) == 0 && strcmp(ps, inputps) == 0)
            {
                printf("로그인에 성공하셨습니다! 관리자 모드로 접속합니다. \n");
                administer();
            }
            else
            {
                printf("로그인에 실패하셨습니다. 초기화면으로 돌아갑니다.\n");
                passcount++;
            }
            if (passcount == 3) // 3번 틀리면 종료
            {
                printf("3번 틀리셨습니다. 프로그램을 종료합니다.\n");
                exit(1);
            }
        }
        else if(choice == 2) // 사용자모드 구현
        {
            printf("사용자 모드를 선택하셨습니다.\n");
            printf("사용자 모드로 접속합니다.\n");
            // user(); 구현해야함
        }
        else if(choice == 3) // 종료
        {
            printf("종료를 선택하셨습니다.\n");
            printf("프로그램을 종료합니다.\n");
            exit(1);
        }
        else
        {
            printf("잘못 입력하셨습니다. 1, 2, 3만 입력해주세요.\n");
        }
    }
}

// 사용자추가 - ??
// 사용자마다 단어장을 다르게 해서 ...

// 함수를 더 쪼개서 만들어라?
// 입력받는 함수
// 출력하는 함수

void administer(void)
{
    int choice2; //단어 입출력을 선택하는 변수
    int choice3; //단어를 계속 입력받거나 종료하는 것을 선택하는 변수
    TEXT input; // 입력받을 단어와 뜻을 가지는 구조체
    TEXT output; // 출력받을 단어와 뜻을 가지는 구조체
    FILE *fp;

    printf("관리자 모드 중 단어를 입력하는 모드는 1번, 단어를 출력하는 모드는 2번을 입력해주세요.\n");
    scanf("%d", &choice2);
    fflush(stdin);
    if(choice2 == 1) {
        if ((fp = fopen("wordmaster.txt", "a")) == NULL) {
            fprintf(stderr, "'wordmaster.txt' 파일을 열 수 없습니다.\n");
            exit(1);
        }
        do {
            printf("단어 입력 모드를 선택하셨습니다.\n");
            printf("단어를 입력해주세요 :"); // 단어를 입력받는다.
            scanf("%s", input.word);
            printf("뜻을 입력해주세요 :"); // 단어의 뜻을 입력받는다.
            scanf("%s", input.mean);
            fprintf(fp, "%s %s\n", input.word, input.mean);
            // 입력받은 단어가 있는지 확인하는 과정 필요
            // 파일 입출력, 파일 포인터 사용
            printf("단어와 뜻을 성공적으로 입력 받았습니다.\n 계속 입력 받으려면 1, 종료하려면 다른 숫자를 입력하십시오.");
            scanf("%d", &choice3);
            fflush(stdin);
            // 관리자 모드 사용
        } while (choice3 == 1);
        fclose(fp);
        printf("초기화면으로 돌아갑니다.\n");
    }
    else if(choice2 == 2)
    {
    if ((fp = fopen("wordmaster.txt", "r")) == NULL) {
        fprintf(stderr, "'wordmaster.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    while( !feof(fp) )
    {
        fscanf(fp, "%s %s", output.word, output.mean);
        printf("%s %s\n", output.word, output.mean);
    }
    fclose(fp);
    printf("전부 출력했습니다. 초기화면으로 돌아갑니다.\n");
    }
    else
    {
        printf("잘못 입력하셨습니다. 1, 2만 입력해주세요.\n");
    }
}