#include <stdio.h>
#include "linkedlist.h"

/*
题目要求:
将数列 a1,a2,a3,....,an 重新排列成新数列
新数列要求 a1,an,a2,a(n-1)...
数列均由单链表(带头节点)存储
*/

// 题目核心函数 reorderlist
void mainfunc(node* l)
{
    node* new_list_first_node = find_middle_node(l,1); // 找到后半部分新链表的第一个节点
    node* new_list = initialize_linkedlist(); // 创建新链表的头节点
    new_list -> next = new_list_first_node; // 将新链表连接到原来链表的后半部分
    node* temp = find_middle_node(l,0);
    temp -> next = NULL; // 删除原链表的后半部分

    reverse_linkedlist(new_list);
    traversal_linkedlist(new_list,1);

    node* p1 = l -> next;
    node* p1_next = p1 -> next;
    node* p2 = new_list -> next;
    node* p2_next = p2 -> next;

    while(p1_next!= NULL)
    {
        p1 -> next = p2;
        p2 -> next = p1_next;

        p1 = p1_next;
        p1_next = p1_next -> next;

        p2 = p2_next;
        p2_next = p2_next -> next;
    }

    p1 -> next = p2;
    

    traversal_linkedlist(l,1);

}



int main()
{
    node* list = initialize_linkedlist();
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,2);
    insert_tail_linkedlist(list,3);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,5);
    insert_tail_linkedlist(list,6);
    insert_tail_linkedlist(list,7);
    insert_tail_linkedlist(list,8);
    insert_tail_linkedlist(list,9);
    traversal_linkedlist(list,1);
    
    mainfunc(list);
    traversal_linkedlist(list,1);





    return 0;
}