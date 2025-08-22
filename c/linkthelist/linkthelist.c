#include <stdio.h>
#include <stdlib.h>
#include "linkthelist.h"

int main()
{   
    List list;
    int number;
    list.head = NULL; //有一个node的指针叫做head(头指针),它一开始等于NULL
    do
    {   
        printf("input a number: ");
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);
        }
    } while (number != -1);

    // 遍历
    print(&list);

    // 搜索一个结点并删除
    printf("which number do you want to delete?\n");
    scanf("%d", &number);
    Node *p,*q;
    int isfound = 0;
    for (p = list.head,q = 0; p;q=p, p = p->next)
    {
        if (p->value == number)
        {
            if ( q )// 判断q是否存在
            {
                q->next = p->next;// 让q跳过p直接指向p的下一个
            }
            else
            {
                list.head = p->next;// 若q不存在,则说明p是链表的第一个结点,把head移向下一个
            }
            printf("find %d\n%d has already been deleted\n", number, number);
            isfound = 1;
            free(p);
            break;
        }
    }
    if (!isfound)
    {
        printf("can not found %d\n",number);
    }

    print(&list);
    clear(&list);
    printf("clear\n");



    return 0;
}


// 清除链表
void clear(List * plist)
{
    Node *p, *q;
    p = plist->head;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    plist->head = NULL;// 将plist->head置为NULL,防止plist->head为野指针,指向已释放的内存
}


// 遍历链表
void print(List * plist)
{
    Node *p;
    for (p = plist->head; p; p = p->next)
    {
        printf("%d\t",p->value);
    }
    printf("\n");
}

// 添加链表
void add(List* plist, int number)
{
    // add to linked-list
    Node *p = (Node *) malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    // find the last 
    Node *last = plist->head;
    if (last)
    {
        while (last->next != NULL)
        {
            last = last->next;
        }

        // attach
        last->next = p; //此时last->next不再是NULL了,而是指向了一块新的内存}
    }
    else
    {
        plist->head = p;
    }
}