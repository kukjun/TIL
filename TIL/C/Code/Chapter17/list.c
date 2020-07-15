// print_list()
void print_list(NODE *plist) //
{
    NODE *p;

    p = plist;
    printf("( ");

    while( p ) // p != NULL과 동일
    {
        printf("%d ", p->data);
        p = p->link // 다음 노드로 진행
    }
    printf(")\n");
}

//get_length()
int get_length(NODE *plist)
{
    NODE *p;
    int length = 0;

    p = plist;

    while( p )
    {
        length++;
        p = p->link;
    }
    printf("리스트의 길이 : %d", length);
    return length;
}

//get_sum()
int get_sum(NODE *plist)
{
    NODE *p;
    int sum = 0;

    p = plist;

    while( p )
    {
        sum += p->data;
        p = p->link;
    }
    printf("리스트의 합계 : %d", sum);
    return sum;
}