#include <stdio.h>
#include <string.h>

int str_chr(char *s, int c);
int main(void)
{
    char i;
    char str[100];
    printf("input str :");
    gets(str);
    for(i=97 ; i<123 ; i++)
    {
        printf("%c = %d\n", i, str_chr(str, i));
    }
    return 0;
}

int str_chr(char *s, int c)
{
    int count = 0;
    while((*s) != '\0') {
        if ((*s) == c) {
            count++;
            *s++;
        } else
            *s++;
    }
    return count;
}