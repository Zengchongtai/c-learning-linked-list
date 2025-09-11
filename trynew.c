#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_DATA 114514



typedef int elementType;

typedef struct NODE{
    elementType data;
    struct NODE* next;
}node;


// 释放链表(头节点不释放)
void release_linkedlist(node* L)
{   
    node* chosen_node;
    node* p = L -> next;
    while(p!=NULL)
    {
        chosen_node = p -> next;
        free(p);
        p = chosen_node;
    }
    L -> next = NULL;
}

// 初始化链表
node* initialise_linkedlist()
{
    node* head = (node*)malloc(sizeof(node));
    head -> data = DEFAULT_DATA;
    head -> next = NULL;
    return head;
}


// 尾插法
void insert_tail(node* L, elementType insert_data)
{
    node* p = L;
    node* new_node = (node*)malloc(sizeof(node));
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    new_node -> data = insert_data;
    new_node -> next = NULL;
    p -> next = new_node;
}


// 头插法
void insert_head(node* L, elementType insert_data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = insert_data;
    new_node -> next = L -> next;
    L -> next = new_node;
}

// 任意位置插入
void insert(node* L, elementType insert_data, int position)
{   
    position--;
    node* p = L;
    node* new_node = (node*)malloc(sizeof(node));
    for (int i=0;i<position;i++)
    {   
        if (p==NULL)return;
        p = p -> next;
    }
    new_node -> data = insert_data;
    new_node -> next = p -> next;
    p -> next = new_node;
}

// 删除节点
void delete_node(node* L, int position)
{   
    position--;
    node* p;
    node* last_p = L;
    for (int i=0;i<position;i++)
    {
        last_p = last_p -> next;
    }
    p = last_p -> next;
    last_p -> next = p -> next;
    free(p);
    p = NULL; // 防止悬空指针（虽然在这个函数中p即将销毁,但这是个好习惯）


}

// 遍历
void traversal_linkedlist(node* L)
{
    node* p = L;
    p = p -> next; // 头节点不存储数据,头节点下一个叫做节点1
    while(p!=NULL)
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\ndone!\n\n");
}

// 获取链表长度
int getlength(node* L)
{
    node* p = L;
    p = p -> next; // 忽略头节点
    int i = 0;
    while(p!=NULL)
    {
        i++;
        p = p -> next;
    }
    return i;
}



int main()
{
    printf("===========");
    node* list = initialise_linkedlist();
    insert_head(list,810);
    insert_head(list,919);
    insert_tail(list,114);
    insert_tail(list,514);
    traversal_linkedlist(list);
    insert(list,1,1);
    traversal_linkedlist(list);
    delete_node(list,2);
    traversal_linkedlist(list);
    printf("length is: %d \n",getlength(list));
    release_linkedlist(list);
    traversal_linkedlist(list);
    printf("length is: %d \n",getlength(list));




    return 0;
}