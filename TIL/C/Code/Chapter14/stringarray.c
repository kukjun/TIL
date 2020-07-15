// 문자열 배열
#include <stdio.h>

int main(void)
{
    int i, n;
    char *fruit[ ] = {
            "apple",
            "blueberry",
            "orange",
            "melon"
    };
    n = sizeof(fruit) / sizeof(fruit[0]);
    for(i=0 ; i<n ; i++)
        printf("%s\n", fruit[i]);
    return 0;
}