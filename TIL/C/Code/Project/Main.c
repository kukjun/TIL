#include <stdio.h>
#include "MyLib.h"

int main(void)
{
    char main_choice;
    char administer_choice;
    char user_choice;
    char *user;

    printf("영어 단어장 프로그램입니다.\n\n");
    while(1)
    {
        main_menu();
        scanf("%c", &main_choice);
        fflush(stdin);
        switch(main_choice)
        {
            case '1':
                login_administer();
                while(1) {
                    fflush(stdin);
                    administer_menu();
                    scanf("%c", &administer_choice);
                    fflush(stdin);
                    if (administer_choice == '1')
                        create_user();
                    else if (administer_choice == '2')
                        delete_user();
                    else if (administer_choice == '3') {
                        printf("메인메뉴로 돌아갑니다.\n");
                        break;
                    } else if (administer_choice == '4') {
                        printf("프로그램을 종료합니다.");
                        exit(0);
                    } else
                        printf("그 외의 경우는 입력받을 수 없습니다.\n다시 입력해주세요\n");
                }
                break;
            case '2':
                login_user();
                while (1)
                {
                    user_menu();
                    scanf("%c", &user_choice);
                    fflush(stdin);
                    if (user_choice == '1')
                        input_wordbook();
                    else if (user_choice == '2')
                        delete_wordbook();
                    else if (user_choice == '3')
                        practice_wordbook();
                    else if (user_choice == '4') {
                        printf("사용자를 변경하기 위해 로그아웃 하겠습니다.\n");
                        login_user();
                    }
                    else if (user_choice == '5')
                    {
                        printf("메인 메뉴로 돌아갑니다.\n");
                        break;
                    }
                    else if (user_choice == '6')
                        exit(1);
                    else
                        printf("그 외의 경우는 입력받을 수 없습니다.\n 다시 입력해주세요.");
                }
                break;
            case '3':
                return 0;
            default:
                printf("그 외의 경우는 입력받을 수 없습니다.\n다시 입력해주세요.\n");
                break;
        }
    }
}