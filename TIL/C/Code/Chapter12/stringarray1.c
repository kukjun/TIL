#include <stdio.h>

int main(void)
{
    int i;
    char menu[5][10] = {
    "init",
    "open",
    "close",
    "read",
    "write"
    };

    for(i=0 ; i<5 ; i++)
        printf("%dst menu : %s\n", i, menu[i]);

    return 0;
}