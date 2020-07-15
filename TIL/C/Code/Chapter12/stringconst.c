#include <stdio.h>
#include <string.h>

int main(void)
{
    char *p1 = "HelloWorld";
    char p2[] = "HelloWorld";

    //strcpy(p1, "Goodbye");

    printf("p1 = %p \n", p1);
    printf("p1 = %s \n", p1);
    printf("\"HelloWorld\" address = %p \n\n", "HelloWorld");

    p1 = "Goodbye"; //가능
    printf("p1 \"Goodbye\" change pointing\n");

    printf("p1 = %p \n", p1);
    printf("p1 = %s \n", p1);
    printf("\"Goodbye\" address = %p \n\n", "Goodbye");
    strcpy(p2, "Goodbye");
    printf("p1 = %p \n", p1);
    printf("p1 = %s \n", p1);
    return 0;
}