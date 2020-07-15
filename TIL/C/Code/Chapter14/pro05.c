#include <stdio.h>
#include <string.h>


void sort_string(char *s[], int size);

int main(void)
{
    char *s[] = { "mycopy", "src", "dst" };
    sort_string(s, 3);
    int i;
    for(i=0 ; i<3 ; i++)
        printf("s[%d] = %s\n", i, s[i]);
    return 0;
}

void sort_string(char *s[], int size)
{
    int i, j, least;
    char *temp;
    for(i=0 ; i<size ; i++)
    {
        least = i;

        for(j=i+1 ; j<size-1 ; j++)
        {
            if(strcmp(s[j], s[least]) > 0)
                least = j;
        }
        temp = s[i];
        *s[i] = *s[least];
        s[least] = temp;
    }
}