#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h> // 디렉토리를 만들기 위해 필요한 헤더파일
#include <direct.h> // 디렉토리 이동을 위해 필요한 헤더파일
#define SIZE 20

char current_user[SIZE] = { 0 };

typedef struct user{
    char id[SIZE];
    char password[SIZE];
    struct user *link;
} USER;

typedef struct wordbook {
    char word[SIZE];
    char mean[SIZE];
    struct wordbook *link;
} WORDBOOK;

int login_administer(void)
{
    int passcount = 0;
    char administer_id[SIZE] = "kukjun";
    char administer_password[SIZE] = "kukkuk123";

    char *input_id = NULL;
    input_id = (char *)calloc( SIZE, sizeof(char) );
    if( input_id == NULL )
    {
        printf("메모리 할당 오류\n 프로그램을 종료합니다.");
        exit(1);
    }
    char *input_password = NULL;
    input_password = (char *)calloc( SIZE,sizeof(char) );
    if( input_password == NULL )
    {
        printf("메모리 할당 오류\n 프로그램을 종료합니다.");
        exit(1);
    }

    printf("관리자 로그인 프로그램을 실행합니다.\n");
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
        else {
            if (passcount == 3) // 3번 틀리면 종료
            {
                printf("3번 틀리셨습니다. 프로그램을 종료합니다.\n");
                free(input_id);
                free(input_password);
                exit(1);
            }
            printf("로그인에 실패하셨습니다. 다시 입력해주세요. (%d / 3)\n", ++passcount);
        }
    }
}

int create_user(void)
{
    USER user1 = { 0 };
    USER check_user[100] = { 0 };
    int max_count, count = 0;
    char password_check[SIZE];
    FILE *fp;
    printf("사용자 생성 프로그램을 실행합니다.\n");
    if ((fp = fopen("user.txt", "r")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    while( !feof(fp) ){
        fscanf(fp, "\n%s %s", check_user[count].id, check_user[count].password);
        count++;
    }
    max_count = count;

    printf("사용자 목록을 불러옵니다.\n");
    for(count=0 ; count<65 ; count++)
        printf("*");
    printf("\n");
    for(count=0 ; count<max_count ; count++)
    {
        printf("Id : %20s\t| Password : %20s\n", check_user[count].id, check_user[count].password);
    }
    for(count=0 ; count<65 ; count++)
        printf("*");
    printf("\n");

    printf("사용자의 아이디를 입력해주세요 : ");
    gets(user1.id);
    while(1) {
        printf("사용자의 비밀번호를 입력해주세요 : ");
        gets(user1.password);
        printf("사용자의 비밀번호를 다시 한번 입력해주세요 :");
        gets(password_check);
        if (strcmp(user1.password, password_check) != 0) {
            printf("비밀번호가 서로 다릅니다. 비밀번호 입력전으로 돌아갑니다.\n");
        }
        else
            break;
    }

    for(count=0 ; count<max_count ; count++) {
        if (strcmp(user1.id, check_user[count].id) == 0) {
            printf("이미 같은 이름의 사용자 id가 있습니다. 초기화면으로 돌아갑니다.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    check_user[max_count] = user1;

    if((fp = fopen("user.txt", "w")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    for(count=0 ; count<=max_count ; count++) {
        fprintf(fp,"\n%s %s", check_user[count].id, check_user[count].password);
    }
    fclose(fp);
    mkdir(user1.id);
    printf("사용자 생성에 성공하였습니다.\n");
    return 0;
}

int delete_user(void) {
    char de_user[SIZE];
    int de_count = 0;
    int i;
    char confirm;
    USER buffer_user;
    USER *list = NULL;
    USER *prev, *p, *next;
    FILE *fp;

    printf("사용자 삭제 프로그램을 실행합니다.\n");
    if ((fp = fopen("user.txt", "r")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    while (!feof(fp)) {
        fscanf(fp, "\n%s %s", buffer_user.id, buffer_user.password);
        p = (USER *) malloc(sizeof(USER));
        strcpy(p->id, buffer_user.id);
        strcpy(p->password, buffer_user.password);

        if (list == NULL)       // 리스트가 비어 있으면
            list = p;           // 새로운 노드를 첫번째 노드로 만든다.
        else                    // 리스트가 비어 있지 않으면
            prev->link = p;     // 새로운 노드를 이전 노드의 끝에 붙인다.
        p->link = NULL;         // 새로운 노드의 링크 필드를 NULL으로 설정
        prev = p;               // 새로운 노드를 이전 노드로 설정한다.
    }
    fclose(fp);

    printf("사용자 목록을 불러옵니다.\n");
    for(i=0 ; i<65 ; i++)
        printf("*");
    printf("\n");
    p = list;
    while( p!=NULL )
    {
        printf("Id : %20s\t| Password : %20s\n", p->id, p->password);
        p = p -> link;
    }
    for(i=0 ; i<65 ; i++)
        printf("*");
    printf("\n");
    printf("삭제할 사용자의 아이디를 입력해주세요 : ");
    scanf("%s", de_user);

    fflush(stdin);

    if ((fp = fopen("user.txt", "w")) == NULL) {
        fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
        exit(1);
    }
    p = list;
    while (p != NULL) {
        if (strcmp(de_user, p->id) == 0) {
            de_count++;
            printf("정말 사용자 아이디 '%s'를 삭제할까요? (y,Y), (n,N) :", p->id);
            scanf("%c", &confirm);
            fflush(stdin);
            if(confirm == 'y' || confirm == 'Y') {
                printf("사용자 아이디 '%s'를 삭제했습니다.\n", p->id);
                rmdir(p->id);
                p = p->link;
                if (p == NULL)
                    break;
            }
            else if(confirm == 'n' || confirm == 'N')
            {
                printf("사용자 아이디 '%s'를 삭제하지 않았습니다.", p->id);
            }
            else
                printf("그 외의 문자는 입력받을 수 없습니다.\n 틀리다고 간주해 '%s'를 삭제하지 않겠습니다.\n", p->id);
        }
        fprintf(fp, "\n%s %s", p->id, p->password);
        p = p->link;
    }
    fclose(fp);
    p = list;
    while(p != NULL){
        next = p->link;
        free(p);
        p = next;
    }
    if (de_count == 0) {
        printf("삭제할 사용자의 아이디가 없습니다.\n");
        return 1;
    }
    return 0;
}

int login_user(void)
{
    USER input_user = { 0 };
    int passcount = 0;
    USER check_user[100] = { 0 };
    int max_count, count = 0;
    FILE *fp;

    printf("사용자 로그인 프로그램을 실행합니다.\n");
    while(1) {
        printf("사용자의 Id를 입력해주세요 : ");
        gets(input_user.id);
        printf("사용자의 Password를 입력해주세요 : ");
        gets(input_user.password);

        if ((fp = fopen("user.txt", "r")) == NULL) {
            fprintf(stderr, "'user.txt' 파일을 열 수 없습니다.\n");
            exit(1);
        }
        while( !feof(fp) ){
            fscanf(fp, "\n%s %s", check_user[count].id, check_user[count].password);
            count++;
        }
        fclose(fp);
        max_count = count;

        for(count=0 ; count<max_count ; count++) {
            if (strcmp(input_user.id, check_user[count].id) == 0 && strcmp(input_user.password, check_user[count].password) == 0) {
                printf("로그인에 성공하셨습니다! 사용자 '%s'로 접속합니다. \n", input_user.id);
                strcpy(current_user, input_user.id);
                return 0;
            }
        }
        if (passcount == 3) // 3번 틀리면 종료
        {
            printf("3번 틀리셨습니다. 프로그램을 종료합니다.\n");
            exit(1);
        }
        printf("로그인에 실패하셨습니다. 다시 입력해주세요. (%d / 3)\n", ++passcount);
    }
}

int input_wordbook(void) {
    WORDBOOK input = {0};
    char user_id[SIZE] = {0};
    WORDBOOK check_wordbook[100] = {0};
    char confirm;
    int max_count, count = 0;
    FILE *fp;

    strcpy(user_id, current_user);
    printf("단어장 입력 프로그램을 실행합니다.\n");
    chdir(user_id);
    strcat(user_id, ".txt");

    if ((fp = fopen(user_id, "r")) == NULL) {
        printf("사용자의 단어장이 아직 만들어지지 않았습니다.\n");
        printf("먼저 단어장을 만들겠습니다. 단어장의 이름은 '%s'입니다.\n", user_id);
        if ((fp = fopen(user_id, "w")) == NULL) {
            fprintf(stderr, "'%s' 파일을 열 수 없습니다.\n", user_id);
            exit(1);
        }
        fclose(fp);
        if ((fp = fopen(user_id, "r")) == NULL) {
            fprintf(stderr, "'%s' 파일을 열 수 없습니다.\n", user_id);
            exit(1);
        }
    }
    while (!feof(fp)) {
        fscanf(fp, "\n%s %s", check_wordbook[count].word, check_wordbook[count].mean);
        count++;
    }
    max_count = count;

    printf("단어 목록을 불러옵니다.\n");
    for(count=0 ; count<61 ; count++)
        printf("*");
    printf("\n");
    for(count=0 ; count<max_count ; count++)
    {
        printf("Word : %20s\t| Mean : %20s\n", check_wordbook[count].word, check_wordbook[count].mean);
    }
    for(count=0 ; count<61 ; count++)
        printf("*");
    printf("\n");

    while (1) {
        printf("단어장에 추가할 단어를 입력해주세요 : ");
        gets(input.word);
        printf("그 단어의 뜻을 입력해주세요 : ");
        gets(input.mean);

        printf("Word : %10s\t | Mean : %10s\n 맞는지 확인해주세요. 맞으면 y(Y), 틀리면 n(N)을 입력해주세요.\n", input.word, input.mean);
        scanf("%c", &confirm);
        fflush(stdin);
        if (confirm == 'y' || confirm == 'Y') {
            break;
        } else if (confirm == 'n' || confirm == 'N')
            printf("다시 입력을 받겠습니다.\n");
        else
            printf("그 외의 문자는 입력받을 수 없습니다.\n 틀리다고 간주해 다시 입력을 받겠습니다.\n");
    }
    for (count = 0; count < max_count; count++) {
        if (strcmp(input.word, check_wordbook[count].word) == 0) {
            printf("이미 같은 단어가 있습니다.\n 사용자 화면으로 돌아갑니다.\n");
            fclose(fp);
            chdir("..");
            return 1;
        }
    }
    fclose(fp);

    check_wordbook[max_count] = input;

    if ((fp = fopen(user_id, "w")) == NULL) {
        fprintf(stderr, "'%s' 파일을 열 수 없습니다.\n", user_id);
        exit(1);
    }
    for (count = 0; count <= max_count; count++) {
        fprintf(fp, "\n%s %s", check_wordbook[count].word, check_wordbook[count].mean);
    }
    fclose(fp);
    printf("** Word : %10s\t Mean : %10s ** 저장에 성공했습니다!\n 사용자 화면"
           "으로 돌아갑니다.\n", input.word, input.mean);
    chdir("..");
    return 0;
}

int delete_wordbook(void)
{

    char de_word[SIZE];
    char user_id[SIZE] = {0};
    char confirm;
    USER buffer_user;
    int i, de_count = 0;
    USER *list = NULL;
    USER *prev, *p, *next;
    FILE *fp;

    strcpy(user_id, current_user);
    printf("단어장 삭제 프로그램을 실행합니다.\n");
    chdir(user_id);
    strcat(user_id, ".txt");

    if ((fp = fopen(user_id, "r")) == NULL) {
        printf("사용자의 단어장이 아직 만들어지지 않았습니다.\n 사용자 화면으로 돌아갑니다.\n");
        chdir("..");
        return 1;
    }

    while (!feof(fp)) {
        fscanf(fp, "\n%s %s", buffer_user.id, buffer_user.password);
        p = (USER *) malloc(sizeof(USER));
        strcpy(p->id, buffer_user.id);
        strcpy(p->password, buffer_user.password);

        if (list == NULL)       // 리스트가 비어 있으면
            list = p;           // 새로운 노드를 첫번째 노드로 만든다.
        else                    // 리스트가 비어 있지 않으면
            prev->link = p;     // 새로운 노드를 이전 노드의 끝에 붙인다.
        p->link = NULL;         // 새로운 노드의 링크 필드를 NULL으로 설정
        prev = p;               // 새로운 노드를 이전 노드로 설정한다.
    }
    fclose(fp);

    printf("단어 목록을 불러옵니다.\n");
    for(i=0 ; i<61 ; i++)
        printf("*");
    printf("\n");
    p = list;
    while( p!=NULL )
    {
        printf("Word : %20s\t| Mean : %20s\n", p->id, p->password);
        p = p -> link;
    }
    for(i=0 ; i<61 ; i++)
        printf("*");
    printf("\n");

    printf("단어장에서 삭제할 단어를 입력해주세요 : ");
    gets(de_word);

    if ((fp = fopen(user_id, "w")) == NULL) {
        fprintf(stderr, "'%s' 파일을 열 수 없습니다.\n", user_id);
        exit(1);
    }

    p = list;
    while (p != NULL) {
        if (strcmp(de_word, p->id) == 0) {
            de_count++;
            printf("정말 단어 '%s'를 삭제할까요? (y,Y = 삭제, n,N =삭제안함) : ", p->id);
            scanf("%c", &confirm);
            fflush(stdin);
            if(confirm == 'y' || confirm == 'Y') {
                printf("단어'%s'를 삭제했습니다.\n", p->id);
                p = p->link;
                if (p == NULL)
                    break;
            }
            else if(confirm == 'n' || confirm == 'N')
            {
                printf("단어'%s'를 삭제하지 않았습니다.", p->id);
            }
            else
                printf("그 외의 문자는 입력받을 수 없습니다.\n 틀리다고 간주해 단어 '%s'를 삭제하지 않았습니다.\n", p->id);
        }
        fprintf(fp, "\n%s %s", p->id, p->password);
        p = p->link;
    }
    fclose(fp);

    p = list;
    while(p != NULL){
        next = p->link;
        free(p);
        p = next;
    }
    if (de_count == 0) {
        printf("삭제할 단어가 없습니다.\n");
        chdir("..");
        return 1;
    }
    chdir("..");
    return 0;
}

int practice_wordbook(void)
{
    char user_id[SIZE] = { 0 };
    char practice_mean[SIZE] = {0};
    WORDBOOK check_wordbook[100] = {0};
    int max_count, count = 0;
    char confirm;
    int all_count=0, success_count=0;
    int random;
    FILE *fp;

    strcpy(user_id, current_user);
    printf("단어장 연습 프로그램을 실행합니다.\n");
    chdir(user_id);
    strcat(user_id, ".txt");

    if ((fp = fopen(user_id, "r")) == NULL) {
        printf("사용자의 단어장이 아직 만들어지지 않았습니다.\n 사용자 화면으로 돌아갑니다.\n");
        chdir("..");
        return 1;
    }
    while (!feof(fp)) {
        fscanf(fp, "\n%s %s", check_wordbook[count].word, check_wordbook[count].mean);
        count++;
    }
    max_count = count;
    fclose(fp);

    while (1) {
        srand(time(NULL));
        random = rand() % max_count;
        printf("Word : %s\n Mean : ", check_wordbook[random].word);
        scanf("%s", practice_mean);
        fflush(stdin);
        if (strcmp(check_wordbook[random].mean, practice_mean) == 0) {
            all_count++;
            success_count++;
            printf("정답입니다!\n 계속하시겠습니까? (y,Y)or(n,N) : ");
            scanf("%c", &confirm);
            fflush(stdin);
        } else {
            all_count++;
            printf("오답입니다..\n 정답은 '%s'입니다.\n 계속하시겠습니까? (y,Y)or(n,N) : ", check_wordbook[random].mean);
            scanf("%c", &confirm);
            fflush(stdin);
        }
        if (confirm == 'y' || confirm == 'Y')
            printf("계속하겠습니다.\n");
        else if (confirm == 'n' || confirm == 'N')
        {
            printf("종료하겠습니다.\n");
            break;
        }
        else {
            printf("그 외의 문자는 입력받을 수 없습니다.\n 임의로 종료하겠습니다.\n");
            break;
        }
    }
    printf("연습결과\n총 횟수 : %d, 성공 횟수 : %d, 성공확률 : %.2lf%%\n", all_count, success_count, success_count/(double)all_count*100);
    chdir("..");
    return 0;
}

void main_menu(void)
{
    printf("\t\t메인 메뉴\n");
    printf("*****************************************\n");
    printf("\t1. 관리자 모드\n");
    printf("\t2. 사용자 모드\n");
    printf("\t3. 종료\n");
    printf("*****************************************\n");
    printf(" : ");
}

void administer_menu(void)
{
    printf("\t\t관리자 메뉴\n");
    printf("*****************************************\n");
    printf("\t1. 사용자 생성\n");
    printf("\t2. 사용자 삭제\n");
    printf("\t3. 메인메뉴로 돌아가기\n");
    printf("\t4. 종료\n");
    printf("*****************************************\n");
    printf(" : ");
}

void user_menu(void)
{
    printf("\t\t사용자 메뉴\n");
    printf("*****************************************\n");
    printf("\t1. 단어 입력 모드\n");
    printf("\t2. 단어 삭제 모드\n");
    printf("\t3. 단어 연습 모드\n");
    printf("\t4. 사용자 변경\n");
    printf("\t5. 메인 메뉴로 돌아가기\n");
    printf("\t6. 종료\n");
    printf("*****************************************\n");
    printf(" : ");
}