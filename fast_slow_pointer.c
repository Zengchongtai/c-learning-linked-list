#include <stdio.h>
#include <stdlib.h>

#define elementType int

typedef struct NODE{
    elementType data;
    struct NODE* next;
}node;


// 初始化链表
node* initialize_linkedlist()
{
    node* head = (node*)malloc(sizeof(node));
    head -> data = 114514;
    head -> next = NULL;
    return head;
}

// 尾插法
void insert_tail(node* L, elementType insert_data)
{
    node* p = L;
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = insert_data;
    while(p -> next!=NULL)
    {
        p = p -> next;
    }
    p -> next = new_node;
    new_node -> next = NULL;
}

// 查找倒数第k个数据 思路: 快慢指针
elementType search_from_bottom(node* L, int k)
{
    node* fast_pointer = L -> next;
    node* slow_pointer = L -> next;
    for (int i=0; i<k; i++)
    {
        fast_pointer = fast_pointer -> next;
    }
    while(fast_pointer!=NULL)
    {
        fast_pointer = fast_pointer -> next;
        slow_pointer = slow_pointer -> next;
    }
    return slow_pointer -> data;
}


int main()
{
    node* list = initialize_linkedlist();

    insert_tail(list,19);
    insert_tail(list,19);
    insert_tail(list,81);
    insert_tail(list,20070207);
    insert_tail(list,123);
    insert_tail(list,989);
    int res = search_from_bottom(list,3);
    printf("%d\n",res);
    // cool!




    return 0;
}