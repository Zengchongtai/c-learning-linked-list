#include <stdio.h>
#include "linkedlist.h"



// 找到有环链表的入口
void find_entry(node* l)
{
    node* fast = l -> next;
    node* slow = l -> next;
    do
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }while(fast!=slow);
    node* first_time_encounter = fast;
    int i=0;
    do
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        i++;
    }while(fast!=slow);

    fast = l -> next;
    slow = l -> next;
    for (int j=0;j<i;j++)
    {
        fast = fast -> next;
    }
    while(fast!=slow)
    {
        fast = fast -> next;
        slow = slow -> next;
    }

    printf("\n\nsuccess!\n\n%d\n\n",fast -> data);
}



int main()
{
    node* list = initialize_linkedlist();
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,2);
    insert_tail_linkedlist(list,3);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,1919810);
    insert_tail_linkedlist(list,5);
    insert_tail_linkedlist(list,6);
    insert_tail_linkedlist(list,7);
    insert_tail_linkedlist(list,8);
    insert_tail_linkedlist(list,9);
    node* p = list;
    for (int i=0;i<4;i++)
    {
        p = p -> next;
    }
    node* p2 =list;
    for (int i=0;i<10;i++)
    {
        p2 = p2 -> next;
    }
    p2 -> next = p -> next;

    /* 链表状况

                            5 -> 6 -> 7 -> 8
                            |              |
    1 -> 2 -> 3 -> 4 -> 1919810      <-    9

    */
    find_entry(list);
}