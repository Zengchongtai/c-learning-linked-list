#include <stdio.h>
#include "linkedlist.h"

#define n 8

/*
题目要求:
[2015](15分)用单链表保存n个整数，结点的结构为[data][link]，且[data]<n(n 为正整数)。
现要求设计一个时间复杂度尽可能高效的算法，对于链表中 data 的绝对值相等的节点，
仅保留第一次出现的节点而删除其余绝对值相等的结点。
*/

// 题目状态: 已完成



// 检查并删除绝对值重复的数字
void mainfunc(node* l)
{
    int num_appear_times[n+1] = {0}; // 数组长度应为n+1 0 1 2 3 4 5 6 7 8 ... n
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
    traversal_linkedlist(test,1);
    mainfunc(test);
    traversal_linkedlist(test,1);

    
    

}