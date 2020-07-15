#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "A joy that's shared is a joy made double";
    char sub[] = "joy";
    char *p;
    int loc;

    p = strstr(s, sub);

    loc = (int)(p - s);
    if ( p != NULL )
        printf("first %s was found %d\n", sub, loc);
    else
        printf("%s wasn't found\n", sub);
    return 0;
}