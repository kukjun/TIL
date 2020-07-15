#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int i;
    int size;
    int count = 0;

    printf("input string :");
    gets(str);

    size = strlen(str);

    for(i=0 ; i<size ; i++)
    {
        if(str[i] == '.' || str[i] == ',')
            count++;
    }
    printf("'.', ',' count : %d\n", count);
    return 0;
}