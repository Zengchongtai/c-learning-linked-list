#include <stdio.h>
#include <stdlib.h>

#define elementType char


typedef struct NODE{
    elementType data;
    struct NODE* next;
}node;

// 初始化链表
node* initialize_linkedlist()
{
    node* head = (node*)malloc(sizeof(node));
    head -> data = ' ';
    head -> next = NULL;
    return head;
}

// 尾插法
void insert_tail(node* L, elementType insert_data)
{
    node* p = L;
    node* new_node = (node*)malloc(sizeof(node));
    while( p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = new_node;
    new_node -> data = insert_data;
}

// 获取单词长度
int getlength(node* L)
{
    node* p = L;// 忽略头节点
    int i = 0;
    while(p->next!=NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

// 题目解决
void resolve(node* l1,node* l2)
{   
    int length_1 = getlength(l1);
    int length_2 = getlength(l2);
    int length_l,length_s;
    node* ll;
    node* ls;
    length_l = length_1;length_s = length_2;ll = l1;ls = l2;
    if (length_1 < length_2)
    {
        length_l = length_2;ll = l2;
        length_s = length_1;ls = l1;
    }
    node* fast_p = ll;
    node* slow_p = ls;
    int steps = length_l - length_s;
    for (int i=0; i<steps; i++)
    {
        fast_p = fast_p -> next;
    }
    while(fast_p!=slow_p)
    {
        fast_p = fast_p -> next;
        slow_p = slow_p -> next;
    }
    printf("\n\nlong word: %c\n\n",fast_p -> data);
    printf("\n\nshort word: %c\n\n",slow_p -> data);
}

int main()
{
    node* str1 = initialize_linkedlist();
    node* str2 = initialize_linkedlist();
    insert_tail(str1,'i');
    insert_tail(str1,'n');
    insert_tail(str1,'t');
    insert_tail(str1,'r');
    insert_tail(str1,'e');
    insert_tail(str1,'s');
    insert_tail(str1,'t');
    insert_tail(str2,'b');
    insert_tail(str2,'e');
    node* i = (node*)malloc(sizeof(node));
    i -> data = 'i';
    node* n = (node*)malloc(sizeof(node));
    n -> data = 'n';
    node* g = (node*)malloc(sizeof(node));
    g -> data = 'g';
    i -> next = n;
    n -> next = g;
    node* p = str1;
    while(p->next!=NULL){p=p->next;}
    p->next=i;
    node* q = str2;
    while(q->next!=NULL){q=q->next;}
    q->next=i;

    resolve(str1,str2);

    return 0;
}