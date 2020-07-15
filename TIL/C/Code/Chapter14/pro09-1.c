#include <stdio.h>

#define HEIGHT 19
#define WIDTH 19
#define EMPTY 1
#define SURVIVE 0
#define TIME 100

void life_game(int b[][WIDTH]);
int condition(int x[][WIDTH], int *p);

int main(void)
{
    int t;
    int i, j;
    int board[HEIGHT][WIDTH];

    for(i=0 ; i<HEIGHT ; i++) // board 초기설정하기
    {
        for(j=0 ; j<WIDTH ; j++)
            board[i][j] = EMPTY;
    }

    board[8][9] = SURVIVE; // board 생존값 설정
    board[9][8] = SURVIVE;
    board[9][9] = SURVIVE;
    board[9][10] = SURVIVE;
    board[10][9] = SURVIVE;

    for(i=0 ; i<HEIGHT ; i++) // 생명게임 전 보드상태 확인
    {
        for(j=0 ; j<WIDTH ; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    for(t=0 ; t<10 ; t++) // 생명 게임 진행, 최대 횟수 제한
    {
        life_game(board); // 생명게임 함수

        for(i=0 ; i<HEIGHT ; i++) // 생명게임 후 보드상태 확인
        {
            for(j=0 ; j<WIDTH ; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        getchar();
    }
    return 0;
}



void life_game(int b[][WIDTH])
{
    int i, j, neighbor;
    int stayboard[HEIGHT][WIDTH]; // 같은 모양으로 생명게임 전 보드를 만들어 복사

    for(i=0 ; i<HEIGHT ; i++) {
        for (j = 0; j < WIDTH; j++) {
            stayboard[i][j] = b[i][j];
        }
    }
    int *sp, *sendp, *p;

    sp = &stayboard[0][0];
    sendp = &stayboard[HEIGHT][WIDTH];

    p = &b[0][0];

    while(sp <= sendp)
    {
        neighbor = 0; // 이웃 값을 초기화해줌
        if(*sp == EMPTY) // 사람이 없는 경우, 출생을 확인
        {
            if( (sp-1) >= &stayboard[0][0] && (sp-1) <= &stayboard[HEIGHT][WIDTH] ) // 범위 안에 있을 경우에만 만족함
            {
                if( *(sp-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH+1) >= &stayboard[0][0] && (sp-WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH+1) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH) >= &stayboard[0][0] && (sp-WIDTH) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH-1) >= &stayboard[0][0] && (sp-WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+1) >= &stayboard[0][0] && (sp+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH-1) >= &stayboard[0][0] && (sp+WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH) >= &stayboard[0][0] && (sp+WIDTH) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH+1) >= &stayboard[0][0] && (sp+WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH+1) == SURVIVE )
                    neighbor++;
            }
            if(neighbor == 3)// 조건 이웃이 3일때,
            {
                *p = SURVIVE; // 사람이 산다.
            }
        }
        else if(*sp == SURVIVE) // 사람이 있는 경우 죽음과 생존을 확인
        {
            if( (sp-1) >= &stayboard[0][0] && (sp-1) <= &stayboard[HEIGHT][WIDTH] ) // 범위 안에 있을 경우에만 만족함
            {
                if( *(sp-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH+1) >= &stayboard[0][0] && (sp-WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH+1) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH) >= &stayboard[0][0] && (sp-WIDTH) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH) == SURVIVE )
                    neighbor++;
            }
            if( (sp-WIDTH-1) >= &stayboard[0][0] && (sp-WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp-WIDTH-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+1) >= &stayboard[0][0] && (sp+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH-1) >= &stayboard[0][0] && (sp+WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH-1) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH) >= &stayboard[0][0] && (sp+WIDTH) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH) == SURVIVE )
                    neighbor++;
            }
            if( (sp+WIDTH+1) >= &stayboard[0][0] && (sp+WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
            {
                if( *(sp+WIDTH+1) == SURVIVE )
                    neighbor++;
            }
            if(neighbor >= 4 || neighbor <= 1)
                *p = EMPTY;
            else
                *p = SURVIVE;
        }
        p++; // 다음으로 넘어감
        sp++; // 전 것도 다음으로 넘어가서 확인
    }
}


int condition(int x[][WIDTH], int *p)
{
    int neighbor = 0;
    if( (sp-1) >= &stayboard[0][0] && (sp-1) <= &stayboard[HEIGHT][WIDTH] ) // 범위 안에 있을 경우에만 만족함
    {
        if( *(sp-1) == SURVIVE )
            neighbor++;
    }
    if( (sp-WIDTH+1) >= &stayboard[0][0] && (sp-WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp-WIDTH+1) == SURVIVE )
            neighbor++;
    }
    if( (sp-WIDTH) >= &stayboard[0][0] && (sp-WIDTH) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp-WIDTH) == SURVIVE )
            neighbor++;
    }
    if( (sp-WIDTH-1) >= &stayboard[0][0] && (sp-WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp-WIDTH-1) == SURVIVE )
            neighbor++;
    }
    if( (sp+1) >= &stayboard[0][0] && (sp+1) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp+1) == SURVIVE )
            neighbor++;
    }
    if( (sp+WIDTH-1) >= &stayboard[0][0] && (sp+WIDTH-1) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp+WIDTH-1) == SURVIVE )
            neighbor++;
    }
    if( (sp+WIDTH) >= &stayboard[0][0] && (sp+WIDTH) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp+WIDTH) == SURVIVE )
            neighbor++;
    }
    if( (sp+WIDTH+1) >= &stayboard[0][0] && (sp+WIDTH+1) <= &stayboard[HEIGHT][WIDTH] )
    {
        if( *(sp+WIDTH+1) == SURVIVE )
            neighbor++;
    }


}