
void administer(void)
{
    int choice2; //단어 입출력을 선택하는 변수
    int choice3; //단어를 계속 입력받거나 종료하는 것을 선택하는 변수
    TEXT input; // 입력받을 단어와 뜻을 가지는 구조체
    TEXT output; // 출력받을 단어와 뜻을 가지는 구조체
    TEXT *fp;

    printf("관리자 모드 중 단어를 입력하는 모드는 1번, 단어를 출력하는 모드는 2번을 입력해주세요.\n");
    scanf("%d", &choice2);
    if(choice2 == 1) {
        fp = fopen("wordmaster.txt", "a");
        if (fp == NULL) {
            printf("파일을 여는데 실패했습니다.\n");
            printf("관리자 모드를 종료합니다.\n");
            exit(1);
        }
        do {
            printf("단어 입력 모드를 선택하셨습니다.\n");
            printf("단어를 입력해주세요 :"); // 단어를 입력받는다.
            scanf("%s", input.word);
            printf("뜻을 입력해주세요 :"); // 단어의 뜻을 입력받는다.
            scanf("%s", input.mean);
            fprintf(fp, "%s %s\n", input.word, input.mean);
            printf("단어와 뜻을 성공적으로 입력 받았습니다.\n 계속 입력 받으려면 1, 종료하려면 다른 숫자를 입력하십시오.");
            scanf("%d", &choice3);
        } while (choice3 == 1);
        fclose(fp);
        printf("초기화면으로 돌아갑니다.\n");
    }
    else if(choice2 == 2)
    {
        fp = fopen("wordmaster.txt", "r");
        if (fp == NULL) {
            printf("파일을 여는데 실패했습니다.\n");
            printf("관리자 모드를 종료합니다.\n");
            exit(1);
        }
        while( !feof(fp) )
        {
            fscanf(fp, "%s %s", &output.word, &output.mean);
            printf("%s %s", output.word, output.mean);
            printf("전부 출력했습니다. 초기화면으로 돌아갑니다.\n");
        }
    }
}