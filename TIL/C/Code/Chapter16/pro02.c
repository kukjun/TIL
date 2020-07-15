#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    FILE *fp1, *fp2;
    char buffer1[100]= { 0 }, buffer2[100] = { 0 };
    char *pb1, *pb2;
    pb1 = &buffer1[0];
    pb2 = &buffer2[0];

    if( (fp1 = fopen("input file.txt", "r")) == NULL)
    {
        fprintf(stderr, "can't open input file");
        exit(1);
    }
    if( (fp2 = fopen("output file.txt", "w")) == NULL)
    {
        fprintf(stderr, "can't open output file");
        exit(1);
    }

    fgets(buffer1, 100, fp1);
    printf("input file : %s\n", buffer1);

    while( *pb1 != 0 )
    {
        *(pb2++) = toupper( *(pb1++) );
    }
    printf("output file : %s", buffer2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}