#include <stdio.h>
#include <string.h>

 struct music {
    int menu;
    char title[20];
    char singer[20];
    char save[20];
    char genre[20];
};

int i=0;

void add(struct music *m);
void print(struct music M, int k);
void search(struct music M, char *A);

 int main(void)
 {
    struct music M[100];
    int choice;
    int k;
    char A[20];

    while(1)
    {
        printf("===========\n1. add\n2. print\n3.search\n4.quit\n==========\n");
        printf("input Menu : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
            case 1:
                add(&M[i]);
                break;
            case 2:
                for(k=0 ; k<i ; k++) {
                    print(M[k], k);
                }
                break;
            case 3:
                printf("input Title :");
                gets(A);
                for(k=0 ; k<i ; k++) {
                    search(M[k], A);
                }
                break;
            default:
                return 0;
        }
    }


 }

 void add(struct music *m)
 {
     printf("Title : ");
     gets(m->title);
     printf("Singer : ");
     gets(m->singer);
     printf("Saving location : ");
     gets(m->save);
     printf("genre : ");
     gets(m->genre);
     i++;
 }

 void print(struct music M, int j)
 {
         printf("Musiclist[%d]\nTitle : %s\nSinger : %s\nSaving location : %s\nGenre : %s\n",j+1 , M.title, M.singer, M.save, M.genre);
 }

 void search(struct music M, char *A)
 {
     if (strcmp(M.title, A) == 0)
     {
         printf("Title : %s\nSinger : %s\nSaving location : %s\nGenre : %s\n", M.title, M.singer, M.save, M.genre);
     }
 }