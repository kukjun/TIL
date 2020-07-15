#include <stdio.h>

void set_proverb(char **q, int n);

int main(void)
{
    char *p;
    int x;
    printf("input number : ");
    scanf("%d", &x);

    set_proverb(&p, x);

    printf("%s\n", p);
    return 0;
}

void set_proverb(char **q, int n)
{
    static char *array[5] = {
            "A bad shearer never had a good sickle.",
            "A bad thing never dies.",
            "A bargain is a bargain.",
            "Fact is stranger than fiction."
            "Failure makes people bitter and cruel. Success improves the character of the man."
    };
    *q = array[n];
}