#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // 디렉토리를 만들기 위해 필요한 헤더파일
#include <direct.h> // 디렉토리 이동을 위해 필요한 헤더파일

int administer_login(void)
{
    int passcount = 0;
    char administer_id[10] = "kukjun";
    char administer_password[10] = "kukkuk123";

    char *input_id = NULL;
    input_id = (char *)calloc( 10, sizeof(char) );
    if( input_id == NULL )
    {
        printf("메모리 할당 오류\n 프로그램을 종료합니다.");
        exit(1);
    }
    char *input_password = NULL;
    input_password = (char *)calloc( 10,sizeof(char) );
    if( input_password == NULL )
    {
        printf("메모리 할당 오류\n 프로그램을 종료합니다.");
        exit(1);
    }

    while(1) {
        printf("관리자 아이디를 입력해주세요 : ");
        scanf("%s", input_id);
        printf("관리자 비밀번호를 입력해주세요 : ");
        scanf("%s", input_password);

        if (strcmp(administer_id, input_id) == 0 && strcmp(administer_password, input_password) == 0)
        {
            printf("로그인에 성공하셨습니다! 관리자 모드로 접속합니다. \n");
            free(input_id);
            free(input_password);
            return 0;
        }
        else
            printf("로그인에 실패하셨습니다. 다시 입력해주세요. (%d / 3)\n", ++passcount);
        if (passcount == 3) // 3번 틀리면 종료
        {
            printf("3번 틀리셨습니다. 프로그램을 종료합니다.\n");
            free(input_id);
            free(input_password);
            return 1;
        }
    }
}

typedef struct user{
    char id[10];
    char password[10];
} USER;

int create_user(void)
{
    USER user1 = { 0 };
    USER check_user[100] = { 0 };
    int max_count, count = 0;
    char password_check[10];
    FILE *fp;
    printf("사용자를 생성하겠습니다.\n 사용자의 아이디를 입력해주세요 : ");
    scanf("%s", user1.id);
    while(1) {
        printf("사용자의 비민번호를 입력해주세요 : ");
        scanf("%s", user1.password);
        printf("사용자의 비밀번호를 다시 한번 입력해주세요 :");
        scanf("%s", password_check);
        if (strcmp(user1.password, password_check) != 0) {
            printf("비밀번호가 서로 다릅니다. 비밀번호 입력전으로 돌아갑니다.\n");
        }
        else
            break;
    }
    if ((fp = fopen("user.txt", "r")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    while( !feof(fp) ){
        fscanf(fp, "%s %s", check_user[count].id, check_user[count].password);
        count++;
    }
    max_count = count;
    for(count=0 ; count <= max_count ; count++) {
        if (user1.id == check_user[count].id) {
            printf("이미 같은 이름의 사용자 id가 있습니다. 초기화면으로 돌아갑니다.");
            free(fp);
            return 1;
        }
    }
    fclose(fp);
    check_user[max_count+1] = user1;
    if((fp = fopen("user.txt", "w")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    for(count=0 ; count<=max_count+1 ; count++) {
        fprintf(fp,"%s %s", check_user[count].id, check_user[count].password);
    }
    fclose(fp);
    mkdir(user1.id);
    printf("사용자 생성에 성공하였습니다.");
    return 0;
}

int delete_user(void)
{

}
