#include <stdio.h>

int main(void)
{
    char s[80];

    printf("input string :");
    scanf("%[abc]", s);
    printf("saved string =%s\n", s);
    return 0;
}