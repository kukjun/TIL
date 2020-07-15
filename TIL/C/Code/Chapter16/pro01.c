#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp1 ,*fp2;
    char file1[10], file2[10];
    char buffer1[100], buffer2[100];

    printf("input first file name : ");
    scanf("%s", file1);
    printf("input second file name : ");
    scanf("%s", file2);

    if ( (fp1 = fopen(file1, "r")) == NULL )
    {
        fprintf(stderr, "error\n can't open %s", file1);
        exit(1);
    }
    if ( (fp2 = fopen(file2, "r")) == NULL )
    {
        fprintf(stderr, "error\n can't open %s", file2);
        exit(1);
    }

    while(fgets(buffer1, 100, fp1) != NULL)
    {
        if(fgets(buffer2, 100, fp2) == NULL)
        {
            printf("different\n");
            exit(1);
        }
        if(strcmp(buffer1, buffer2) != 0)
        {
            printf("different\n");
            exit(1);
        }
    }
    if(fgets(buffer2, 100, fp2) != NULL)
    {
        printf("different\n");
        exit(1);
    }
    else
        printf("same");

    return 0;
}