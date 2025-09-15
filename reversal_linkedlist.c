#include <stdio.h>
#include "linkedlist.h"


// 反转链表
void reverse_linkedlist(node* l)
{   

    // 添加边界条件检查
    if (l->next == NULL || l->next->next == NULL) {
        return; // 空链表或只有一个节点，无需反转
    }


    node* f; // first
    node* s; // second
    node* t; // third
    f = NULL;
    s = l -> next;
    t = s -> next;

    while(t!=NULL)
    {
        s -> next = f;
        f = s;
        s = t;
        t = s -> next;
    }
    s -> next = f; // 第一次写忽略致出错 将最后一个节点(也就是反转后新链表的第一个节点)连接到倒数第二个节点上(也就是反转后新链表的第二个节点)
    l -> next = s; // 第一次写忽略致出错 更新头节点指向第一个节点
}
/*

====== 大致实现思路 ======

null    1           2   3   4   5   6
^       ^           ^
|       |           |
first   second      third

null    1       2           3   4   5   6
        ^       ^           ^
        |       |           |
        first   second      third

先让s指向f
再更新f移到s位置上
再更新s移到t位置上
再更新t移到s的下一个位置上

循环即可.

====== 其他思路 ======

遍历,新建一个链表,然后头插法即可.

*/


int main()
{
    node* list = initialize_linkedlist();
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,5);
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,9);
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,9);
    insert_tail_linkedlist(list,8);
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,0);
    traversal_linkedlist(list,0);
    reverse_linkedlist(list);
    traversal_linkedlist(list,0);
}