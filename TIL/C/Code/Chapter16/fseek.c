#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
void init_table(int table[], int size);

int main(void) {
    int table[SIZE];
    int n, data;
    long pos;
    FILE *fp = NULL;

    init_table(table, SIZE);

    if ((fp = fopen("sample.dat", "wb")) == NULL) {
        fprintf(stderr, "can't open file of output.\n");
        exit(1);
    }

    fwrite(table, sizeof(int), SIZE, fp);
    fclose(fp);

    // 이진 파일을 읽기 모드로 연다.
    if ((fp = fopen("sample.dat", "rb")) == NULL) {
        fprintf(stderr, "can't open file of input.\n");
        exit(1);
    }

    // 사용자가 성택한 위치의 정수를 파일로부터 읽는다.
    while (1) {
        printf("input location in file (0 - %d, quit = -1) :", SIZE-1);
        scanf("%d", &n);
        if (n == -1) break;
        pos = (long) n * sizeof(int);
        fseek(fp, pos, SEEK_SET);
        fread(&data, sizeof(int), 1, fp);
        printf("%d location answer is %d. \n", n, data);
    }
    fclose(fp);

    return 0;
}


void init_table(int table[], int size)
{
    int i;

    for(i=0 ; i<size ; i++)
        table[i] = i*i;
}