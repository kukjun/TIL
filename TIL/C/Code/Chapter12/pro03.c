#include <stdio.h>
#include <string.h>

int str_chr(char *s, int c);

int main(void)
{
    char str[20];
    char count_text;

    printf("input string : ");
    gets(str);
    printf("input count number : ");
    scanf("%c", &count_text);
    printf("%c count : %d", count_text, str_chr(str, count_text));


    return 0;
}

int str_chr(char *s, int c)
{
    int count = 0;
    while((*s) != '\0') {
        if ((*s) == c) {
            count++;
            s++;
        } else
            s++;
    }
    return count;
}