#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("sample.txt", "w");
    if( fp == NULL )
        printf("file open fail\n");
    else
        printf("file open success\n");
    fputc('a', fp);
    fputc('b', fp);
    fputc('c', fp);
    fclose(fp);
    return 0;
}