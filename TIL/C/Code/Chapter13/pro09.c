#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
    char name[20];
    char housephone[20];
    char phone[20];
};

int main(void)
{
    struct A a[3] = {
            {"AA", "273-1234", "1234-5678"},
            {"BB", "273-2345", "1234-6789"},
            {"CC", "273-3456", "1234-7890"}
    };
    char T[20];
    int i;
    printf("input name\n");
    scanf("%s", T);
    for(i=0 ; i<3 ; i++)
    {
        if(strcmp(a[i].name, T) == 0)
            printf("%s number = %s", T, a[i].phone);
    }
    return 0;
}