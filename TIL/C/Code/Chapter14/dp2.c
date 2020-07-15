#include <stdio.h>

void set_pointer(char **q);
char *proverb = "All that glisters is not gold.";

int main(void)
{
    char *p = "zzz";
    set_pointer(&p);
    printf("%s\n", p);
    return 0;
}

void set_pointer(char **q){
    *q = proverb; // 문자열 상수이므로 **q = &proverb는 불가능
}
