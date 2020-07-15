#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100];
    int count = 0;
    char *token;

    printf("input string :");
    gets(str);

    token = strtok(str, " "); //마지막에 count추가되므로 처음을 빼줌
    while (token != NULL) {
        token = strtok(NULL, " ");
        count++; // 마지막 루프때 count 한번 더 증가
    }
    printf("count : %d\n", count);
    return 0;
}