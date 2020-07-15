#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) // 외부 입력을 받을 수 있는 main
{
    int i;
    FILE *fp1, *fp2, *fp3;
    char *file1[200], file2[200][200];

    if( (fp1 = fopen(argv[1], "r")) == NULL )
    {
        fprintf(stderr, "can't open %s.", argv[1]);
        exit(1);
    }
    if( (fp2 = fopen(argv[2], "r")) == NULL )
    {
        fprintf(stderr, "can't open %s.", argv[2]);
        exit(1);
    }
    if( (fp3 = fopen(argv[3], "w")) == NULL )
    {
        fprintf(stderr, "can't open %s.", argv[3]);
        exit(1);
    }
    fscanf(fp1, "%s", file1);
    fscanf(fp2, "%s", file2);
    strcat(file1, file2);
    fprintf(fp3, "%s", file1);

    printf("%s add %s, answer %s.\n", argv[1], argv[2], argv[3]);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}