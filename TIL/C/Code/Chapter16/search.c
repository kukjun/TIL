#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char fname[128];
    char buffer[256];
    char word[256];
    int line_num = 0;

    printf("input file name for using :");
    scanf("%s", fname);

    printf("input file name for searching :");
    scanf("%s", word);

    if( (fp = fopen(fname, "r")) == NULL)
    {
        fprintf(stderr,"can't open this file.\n", fname);
        exit(1);
    }
    while( fgets(buffer, 256, fp) )
    {
        line_num++;
        if( strstr(buffer, word) )
            printf("%s: %d word %s finded.\n", fname, line_num, word );
    }
    fclose(fp);

    return 0;
}