#include <stdio.h>
#include <string.h>

int main(void)
{
    char dsc[100]="Hello World";
    char src[100]="Hello Hello World";
    printf("%p\n", strcpy(dsc, src));
    printf("%p\n", dsc);
    printf("%s\n", strcpy(dsc, src));
    puts(dsc);

    printf("success");
    return 0;

}