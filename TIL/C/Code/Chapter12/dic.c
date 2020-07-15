#include <stdio.h>
#include <string.h>
#define WORDS 5

int main(void)
{
    int i, index;
    char dic[WORDS][2][30] = {
            {"book", "chek"},
            {"boy", "soneun"},
            {"computer", "computer2"},
            {"lanuguage", "Anaer"},
            {"rain", "bi"}
    };
    char word[30];

    printf("input word : ");
    scanf("%s", word);

    index = 0;
    for(i=0 ; i<WORDS ; i++)
    {
        if( strcmp(dic[index][0], word) == 0)
        {
            printf("%s: %s\n", word, dic[index][1]);
            return 0;
        }
        index++;
    }
    printf("can't found");

    return 0;
}