#include <stdio.h>

int main(void)
{
    char c;
    char s[80], t[80];

    printf("input string segurated space :");
    scanf("%s%c%s", s, &c, t);

    printf("string s = %s\n", s);
    printf("character c = %c\n", c);
    printf("string t = %s\n", t);

    return 0;
}