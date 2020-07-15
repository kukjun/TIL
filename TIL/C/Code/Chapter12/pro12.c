#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    char str2[3][15];
    int i=0, j;
    char *token;

    printf("input string :");
    gets(str);

    token = strtok(str, " ");

    while (token != NULL) {
        strcpy(str2[i++], token);
        token = strtok(NULL, " ");
    }
    for(j=i-1 ; j>=0 ; j--) {
        printf("%s ", str2[j]);
        if(j == 1)
            printf(",");
    }
    return 0;
}