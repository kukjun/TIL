#include <stdio.h>

int main(void)
{
    char str[30] = "C language is easy";
    int i = 0;

    while(str[i] != 0)
        i++;
    printf("string \"%s\" length %d\n", str, i);

    return 0;
}