#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    char title[100];
    double rating;
} MOVIE;

int main(void)
{
    MOVIE *movies;
    int size, i;
    printf("몇 편이나 저장하시겠습니까? :");
    scanf("%d", &size);

    movies = (MOVIE *)malloc(sizeof(MOVIE)*size);
    if(movies == NULL)
    {
        printf("동적메모리 할당 오류\n");
        exit(1);
    }
    for(i=0 ; i<size ; i++)
    {
        printf("영화 제목 :");
        fflush(stdin);
        gets(movies[i].title);
        printf("영화 평점");
        scanf("%lf", &movies[i].rating);
    }

    printf("===================================\n");
    printf("제목 \t 평점 \n");
    printf("===================================\n");
    for(i=0 ; i<size ; i++)
        printf("%s \t %f \n", movies[i].title, movies[i].rating);
    free(movies);
    return 0;
}