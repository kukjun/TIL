#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[100];
    int size;

    printf("input string :");
    gets(str);

    size = strlen(str);

    if (islower(str[0]) != 0)
        str[0] = toupper(str[0]);

    if (str[size - 1] != '.')
        str[size] = '.';

    printf("%s", str);

    return 0;
}