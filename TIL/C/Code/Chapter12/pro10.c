#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_upper(char *s);
int main(void) {
    char str[100];
    int size;
    int i;
    int s_count = 0;

    printf("input string :");
    gets(str);

    size = strlen(str);

    str_upper(str);

    for(i=0 ; i<(size)/2 ; i++)
    {
        if(str[i] == str[size-1-i])
            s_count++;
    }
    if(s_count == size/2)
        printf("success\n");
    else
        printf("fail\n");
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