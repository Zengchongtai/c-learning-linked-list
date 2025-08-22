#include <stdio.h>
#include <stdlib.h>
#include "linkthelist.h"


void add(List* plist, int number);
int main()
{   
    List list;
    int number;
    list.head = NULL; //有一个node的指针叫做head(头指针),它一开始等于NULL
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            add(&list, number);

        }
    } while (number != -1);
    return 0;
}

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