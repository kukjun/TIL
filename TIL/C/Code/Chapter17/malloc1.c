#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *score;
    int i;

    score = (int *)malloc( 100*sizeof(int) );
    if( score == NULL )
        {
        printf("동적메모리 할당오류");
        exit(1);
        }

    for(i=0 ; i<100 ; i++)
    {
        score[i] = 0;
        printf("score[%d] = %d\n", i, score[i]);
    }

    free(score);

    return 0;
}