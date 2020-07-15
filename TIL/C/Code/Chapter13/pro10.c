#include <stdio.h>

struct card {
    int value;
    char suit;
};

int main(void)
{
    struct card C[52];
    int i;
    for(i=1 ; i<=52 ; i++)
    {
        if(i<=13)
        {
            C[i-1].suit = 'c';
            C[i-1].value = i;
        }
        else if(i<=26)
        {
            C[i-1].suit = 'd';
            C[i-1].value = i-13;
        }
        else if(i<=39)
        {
            C[i-1].suit = 'h';
            C[i-1].value = i-26;
        }
        else
        {
            C[i-1].suit = 'd';
            C[i-1].value = i-39;
        }
    }
    for(i=0 ; i<=51 ; i++)
        printf("%c, %d \n", C[i].suit, C[i].value);
    return 0;
}