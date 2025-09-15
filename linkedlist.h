// linkedlist.h
// 此代码用以提供标准的单链表
// 以下有关链表位置顺序: 头指针(0节点) -> 1节点 -> 2节点 ...

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

#define elementType int
#define DEFAULT_HEAD_NODE_DATA 114514 // 头节点默认数据

// 定义链表节点结构体
typedef struct NODE{
    elementType data;
    struct NODE* next;
}node;

// 函数声明
int getlength_linkedlist(node* l);
node* initialize_linkedlist();
void insert_tail_linkedlist(node* l, elementType insert_data);
void insert_head_linkedlist(node* l, elementType insert_data);
void insert_linkedlist(node* l, elementType insert_data, int position);
void traversal_linkedlist(node* l, int print_config);
void delete_node(node* l, int position);
node* find_middle_node(node* l, int return_config);
void clear_linkedlist(node* l, int clear_config);
void reverse_linkedlist(node* l);

#endif // _LINKEDLIST_H_