#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define elementType int
#define n 8

/*
题目要求:
[2015](15分)用单链表保存n个整数，结点的结构为[data]link]，且ldatal<n(n 为正整数)。
现要求设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的节点，
仅保留第一次出现的节点而删除其余绝对值相等的结点。
*/

// 题目状态: 已完成

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

// 检查并删除绝对值重复的数字
void mainfuc(node* l)
{
    int num_appear_times[n] = {0};
    for (int i=0;i<n;i++)
    {
        num_appear_times[i] = 0;
    }

    node* p = l -> next; // 从第一个(不是头节点)开始
    node* last_of_p = l; // p的上一个
    elementType res;
    for (int i=0;i<n;i++)
    {   
        res = abs(p -> data);

        // 检查是否重复
        if (num_appear_times[res]>=1) // 重复了,需要删除该节点
        {
            last_of_p -> next = p -> next;
            node* temp = p;
            p = p -> next;
            free(temp);
        }
        else
        {
            num_appear_times[res]++;
            p = p -> next;
            last_of_p = last_of_p -> next;
        }

    }
}

// 遍历
void traversal_linkedlist(node* l)
{
    node* p = l -> next; // 忽略头指针
    printf("\n\n===== start traversal =====\n\n");
    while(p!=NULL)
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\n\n===== end traversal =====\n\n");
}






int main()
{   
    node* test = initialize_linkedlist();
    insert_tail_linkedlist(test,4);
    insert_tail_linkedlist(test,7);
    insert_tail_linkedlist(test,-1);
    insert_tail_linkedlist(test,2);
    insert_tail_linkedlist(test,-4);
    insert_tail_linkedlist(test,8);
    insert_tail_linkedlist(test,1);
    insert_tail_linkedlist(test,4);
    traversal_linkedlist(test);
    mainfuc(test);
    traversal_linkedlist(test);

    
    

}