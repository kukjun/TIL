#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    char str2[10][15];
    char find[10];
    char change[10];
    int i=0, j;
    char *token;

    printf("input string :");
    gets(str);

    token = strtok(str, " ");

    while (token != NULL) {
        strcpy(str2[i++], token);
        token = strtok(NULL, " ");
    }

    printf("input found string : ");
    gets(find);
    printf("input change string : ");
    gets(change);

    for(j=0 ; j<=i-1 ; j++){
        if(strcmp(find, str2[j]) == 0)
            strcpy(str2[j], change);
    }

    for(j=0 ; j<=i-1 ; j++)
        printf("%s ", str2[j]);
    return 0;
}
