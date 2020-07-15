#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int c;

    fp = fopen("sample.txt", "r");
    if( fp == NULL )
        printf("file open fail\n");
    else
        printf("file open success\n");
    while((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    return 0;
}