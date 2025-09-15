// linkedlist.c
#include "linkedlist.h"

// [代码置顶] 获取链表长度 链表头指针 (返回结果不包含头指针)
int getlength_linkedlist(node* l)
{
    node* p = l -> next;
    int num = 0;
    while(p!=NULL)
    {
        p = p -> next;
        num++;
    }
    return num;
}

// 初始化链表 提供指针
node* initialize_linkedlist()
{
    node* head = (node*)malloc(sizeof(node));
    head -> data = DEFAULT_HEAD_NODE_DATA;
    head -> next = NULL;
    return head;
}

// 尾插法 链表头指针 插入数据
void insert_tail_linkedlist(node* l, elementType insert_data)
{
    node* p = l;
    node* new_node = (node*)malloc(sizeof(node));

    while(p->next!=NULL)
    {
        p = p -> next;
    }

    p -> next = new_node;
    new_node -> data = insert_data;
    new_node -> next =NULL;
}

// 头插法 链表头指针 插入数据
void insert_head_linkedlist(node* l, elementType insert_data)
{
    node* new_node = (node*)malloc(sizeof(node));

    new_node -> data = insert_data;
    new_node -> next = l -> next;
    l -> next = new_node;
}

// 任意位置插入 链表头指针 插入数据 插入位置(不计头指针,如输入4,则在第4个和第5个之间插入)
void insert_linkedlist(node* l, elementType insert_data, int position)
{
    node* new_node = (node*)malloc(sizeof(node));
    node* p = l;

    new_node -> data = insert_data;

    for (int i=0;i<position;i++)
    {
        p = p -> next;
    }

    new_node -> next = p -> next;
    p -> next = new_node;
}

// 遍历链表并打印 链表头指针 是否输出头指针(print_config=0输出,print_config=1或其他不输出)
void traversal_linkedlist(node* l, int print_config)
{   
    node* p;
    if (print_config==0){p = l;}
    else {p = l -> next;}
    printf("\n\n===== start traversing  =====\n");
    while(p!=NULL)
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\n===== traverse finished =====\n\n");
}



// 删除节点 链表头指针 节点位置
void delete_node(node* l, int position)
{   
    if (position<=0 || position>getlength_linkedlist(l)){return;}
    position--;
    node* p = l;
    for (int i=0;i<position;i++)
    {
        p = p -> next;
    }
    node* node_need_to_be_deleted = p -> next;
    p -> next = node_need_to_be_deleted -> next;
    free(node_need_to_be_deleted);
    node_need_to_be_deleted = NULL;
}

// 删除中间节点(若链表个数为偶数,则删除中间靠后那个节点均不计头节点) 链表头指针
// 实现思路: 快慢指针
void delete_middle_node(node* l)
{
    node* fast = l -> next;
    node* slow = l; // 慢指针 负责定位中间节点的前置节点
    while(fast!=NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    node* temp = slow -> next;
    slow -> next = temp -> next;
    free(temp);
    temp = NULL;
}

// 清空链表 链表头指针 清空设置(clear_config=0删除整个链表,包括头指针;clear_config=1仅保留头指针,其余全部清空)
void clear_linkedlist(node* l, int clear_config)
{   
    node* p;
    if (clear_config==0){p = l;}
    else {p = l -> next;}
    node* temp = p;
    while(p!=NULL)
    {
        p = p -> next;
        free(temp);
        temp = p;
    }
    if (clear_config!=0)
    {
        l -> next = NULL;
    }
}

// 反转链表(头指针保持不变) 链表头指针
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

void reverse_linkedlist(node* l)
{
    node* f = NULL; // first
    node* s = l -> next;
    node* t = s -> next;

    while(t!=NULL)
    {
        s -> next = f;
        f = s;
        s = t;
        t = s -> next;
    }
    s -> next = f; // 将最后一个节点(也就是反转后新链表的第一个节点)连接到倒数第二个节点上(也就是反转后新链表的第二个节点)
    l -> next = s; // 更新头节点指向第一个节点
}



