#include <stdio.h>
#include <stdlib.h>

char *get_word();

int main(void)
{
    free(get_word());
    return 0;
}

char *get_word()
{
    char *word;
    word = (char *)malloc(50*sizeof(char));
    if (word == NULL)
    {
        printf("메모리 할당 오류 \n");
        exit(1);
    }

    printf("단어를 입력하세요 : ");
    scanf("%s", word);

    printf("동적 메모리에 저장된 단어는 %s 입니다.", word);
    return word;
}