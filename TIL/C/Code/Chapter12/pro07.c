#include <stdio.h>
#include <string.h>

int get_response(char *prompt);
int main(void)
{
    char prompt[10];
    printf("%d", get_response(prompt));
    return 0;
}

int get_response(char *prompt)
{
    printf("Do you wanna play the game ??");
    gets(prompt);
    if(strcmp(prompt, "yes") == 0)
        return 1;
    else if(strcmp(prompt, "no") == 0)
        return 0;
    else
        return -1;
}