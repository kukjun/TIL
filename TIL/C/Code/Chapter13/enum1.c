#include <stdio.h>

enum days { SUN, MON, TUE, WED, THU, FRI, SAT } d;
char *days_name[] = {
        "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"
};
int main(void)
{
    d = WED;
    printf("%d nd days = %s \n", d, days_name[d]);
    return 0;
}