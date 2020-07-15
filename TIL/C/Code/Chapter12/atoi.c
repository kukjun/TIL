#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s1[] = "100";
    char s2[] = "12.93";
    char buffer[100];

    int i;
    double d;
    double result;

    i = atoi(s1);
    d = atof(s2);

    result = i + d;

    sprintf(buffer, "%.3lf", result);
    printf("result of calculation is %s\n", buffer);

    return 0;
}