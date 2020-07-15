#include <string.h>
#include <stdio.h>

int main(void)
{
    char s[] = "language";
    char c = 'g';
    char *p;
    int loc;

    p = strchr(s, c);
    loc = (int)( p - s );
    if ( p != NULL)
        printf("first %c was found %d\n", c, loc );
    else
        printf("%c was't found", c);

}