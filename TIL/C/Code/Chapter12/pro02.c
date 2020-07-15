#include <stdio.h>
#include <string.h>

void del_space(char *text);

int main(void)
{
    char text[30];

    printf("input text included space : ");
    gets(text);

    del_space(text);

    return 0;
}

void del_space(char *text)
{
    char *token;

    token = strtok(text, " ");
    while(token != NULL)
    {
        printf("%s", token);
        token = strtok(NULL, " ");
    }
}