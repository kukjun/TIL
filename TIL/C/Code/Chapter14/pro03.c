#include <stdio.h>

void pr_str_array(char **pr, int n);

int main(void)
{
    char *A[] = {
            "Hi", "Hello", "ABCD", "EFGH", "LMNOP"
    };
    int size;
    size = sizeof(A) / sizeof(A[0]);
    pr_str_array(A, size);

    return 0;
}
void pr_str_array(char **pr, int n)
{
    int i;
    for(i=0 ; i<n ; i++)
    {
        printf("%s\n", *pr);
        *pr++;
    }
}