#include <stdio.h>

int main(void)
{
    if( remove("sample.txt") == -1)
        printf("sample.txt was can't remove.\n");
    else
        printf("sample.txt was removed.\n");
    return 0;
}