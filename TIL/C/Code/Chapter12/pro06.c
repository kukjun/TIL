#include <stdio.h>
#include <ctype.h>

void str_upper(char *s);
int main(void)
{
    char str[100];
    printf("input string :");
    gets(str);
    str_upper(str);
    printf("changed string : %s\n", str);
    return 0;
}

void str_upper(char *s)
{
    while(*s != '\0')
    {
        if(*s >= 97 && *s <= 122){
            *s = toupper(*s);
            s++;
        }
        else
            s++;
    }
}