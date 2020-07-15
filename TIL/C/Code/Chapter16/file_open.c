// 파일 열기
#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("sample.txt", "w");
    if( fp == NULL )
        printf("file open fail\n");
    else
        printf("file open success\n");
    fclose(fp);
    return 0;
}