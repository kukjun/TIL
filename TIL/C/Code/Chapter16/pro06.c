#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    FILE *fp1;
    char fname[10];
    char c;
    int count = 0;

    printf("input file name : ");
    scanf("%s", fname);

    if( (fp1 = fopen(fname, "r")) == NULL )
    {
        fprintf(stderr, "we can not open file of grade %s.\n", fname);
        exit(1);
    }

    while( (c = fgetc(fp1)) != EOF )
    {
        if(isprint(c) != 0)
        {
            count++;
        }
    }
    fclose(fp1);
    printf("count : %d", count);

    return 0;
}