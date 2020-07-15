// 함수 포인터 배열
#include <stdio.h>

// 함수 원형 정의
void menu(void);
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);

void menu(void)
{
    printf("=====================\n");
    printf("0. ADD\n");
    printf("1. SUB\n");
    printf("2. MUL\n");
    printf("3. DIV\n");
    printf("else. Quit\n");
    printf("=====================\n");
}

int main(void)
{
    int choice, result, x, y;
    // 함수 포인터 배열을 선언하고 초기화한다.
    int (*pf[4])(int, int) = { add, sub, mul, div };

    while(1) {
        menu();

        printf("select menu : ");
        scanf("%d", &choice);

        if (choice < 0 || choice >= 4)
            break;

        printf("input two number : ");
        scanf("%d %d", &x, &y);

        result = pf[choice](x, y);

        printf("result : %d\n", result);
    }
    return 0;
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}