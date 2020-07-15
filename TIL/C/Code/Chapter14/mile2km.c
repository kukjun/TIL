// main 함수의 인수 활용
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double mile, km;
    if( argc != 2){
        printf("Using Way : mile2km Dis\n");
        return 1;
    }

    mile = atof(argv[1]);
    km = 1.609 * mile;

    printf("Input distance = %d km\n", km);

    return 0;
}
