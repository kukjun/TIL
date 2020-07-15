#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[80];
    char s2[80];
    int result;

    printf("input first word : ");
    scanf("%s", s1);
    printf("input second word : ");
    scanf("%s", s2);

    result = strcmp(s1, s2);
    if( result < 0 )
        printf("%s is front then %s\n", s1, s2);
    else if( result == 0)
        printf("%s is same that %s\n", s1, s2);
    else
        printf("%s is behind then %s\n", s1, s2);
    return 0;
}