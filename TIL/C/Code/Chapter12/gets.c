#include <stdio.h>

int main(void)
{
    char name[100];
    char address[100];

    printf("input name: ");
    gets(name);
    printf("input your address: ");
    gets(address);

    puts(name);
    puts(address);
    return 0;
}