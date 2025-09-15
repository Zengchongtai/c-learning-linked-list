#include <stdio.h>
#include "linkedlist.h"

/*
[ 删除链表的中间节点 ]
 若链表个数为偶数,则删除中间靠后那个节点
 均不计头节点

 题目状态: 已完成
*/


// 删除中间节点
void delete_middle_node(node* l)
{
    node* fast = l -> next;
    node* slow = l;
    while(fast!=NULL && fast->next!=NULL)
    {   
        fast = fast -> next -> next; // 快指针走两步
        slow = slow -> next; // 慢指针走一步 
    }
    // 快指针走到最后一个节点时慢指针恰好指向中间节点的前一个节点
    node* temp;
    temp = slow -> next;
    slow -> next = temp -> next;
    free(temp);
    temp = NULL;
}



int main()
{
    node* list = initialize_linkedlist();
    insert_tail_linkedlist(list,1);
    insert_tail_linkedlist(list,2);
    insert_tail_linkedlist(list,3);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,5);
    insert_tail_linkedlist(list,4);
    insert_tail_linkedlist(list,3);
    insert_tail_linkedlist(list,2);
    insert_tail_linkedlist(list,1);
    traversal_linkedlist(list,1);
    delete_middle_node(list);
    traversal_linkedlist(list,1);

}