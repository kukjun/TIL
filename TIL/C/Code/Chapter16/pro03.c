#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
    int buffer[SIZE];
    FILE *fp1, *fp2;

    if( (fp1 = fopen("binary.bin", "rb")) == NULL)
    {
        fprintf(stderr, "binary.bin file can not open.");
        exit(1);
    }
    if( (fp2 = fopen("binary_copy.bin", "wb")) == NULL)
    {
        fprintf(stderr, "binary_copy.bin file can not open.");
        exit(1);
    }
    fread(buffer, sizeof(int), SIZE, fp1);
    fwrite(buffer, sizeof(int), SIZE, fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}