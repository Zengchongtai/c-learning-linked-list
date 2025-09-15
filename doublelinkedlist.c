#include <stdio.h>
#include <stdlib.h>

#define elementType int
#define DEFAULT_HEAD_DATA 114514

typedef struct NODE{
    elementType data;
    struct NODE *prev,*next;
}node;


// 初始化链表
node* initialize_doublelinkedlist()
{
    node* head = (node*)malloc(sizeof(node));
    head -> data = DEFAULT_HEAD_DATA;
    head -> prev = NULL;
    head -> next = NULL;
    return head;
}

// 尾插法 链表头指针 插入数据
void insert_tail_doublelinkedlist(node* dl, elementType insert_data)
{
    node* p = dl;
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = insert_data;
    while(p->next!=NULL)
    {
        p = p -> next;
    }
    p -> next = new_node;
    new_node -> prev = p;
    new_node -> next = NULL;
}

// 头插法 链表头指针 插入数据
void insert_head_doublelinkedlist(node* dl, elementType insert_data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = insert_data;

    new_node -> next = dl -> next;
    new_node -> prev = dl;
    dl -> next = new_node;
    if (new_node -> next != NULL)
    {
        new_node -> next -> prev = new_node;
    }
}

// 在任意位置插入 链表头指针 插入数据 插入位置
void insert_doublelinkedlist(node* dl, elementType insert_data, int position)
{
    // 暂时还未进行边界验证
    node* new_node = (node*)malloc(sizeof(node));
    node* p = dl;
    new_node -> data = insert_data;
    for (int i=0;i<position;i++)
    {
        p = p -> next;
    }
    new_node -> prev = p;
    new_node -> next = p -> next;
    p -> next = new_node;
    if (new_node->next!=NULL)
    {
        new_node -> next -> prev = new_node;
    }
}

// 遍历双向链表
void traversal_doublelinkedlist(node* dl)
{
    node* p = dl -> next;
    printf("\n\n====== start traversing  ======\n");
    while(p!=NULL)
    {   
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("\n====== traverse finished ======\n\n");
}

// 删除节点
void delete_node(node* dl, int position)
{
    node* p = dl;
    for (int i=0;i<position;i++)
    {
        p = p -> next;
    }
    if (p -> next!=NULL)
    {
        p -> next -> prev = p -> prev;
    }
    p -> prev -> next = p -> next;
    free(p);
    p = NULL;
}




int main()
{
    node* dlist = initialize_doublelinkedlist();
    insert_tail_doublelinkedlist(dlist,1);
    insert_tail_doublelinkedlist(dlist,4);
    insert_head_doublelinkedlist(dlist,4);
    insert_head_doublelinkedlist(dlist,1);
    insert_head_doublelinkedlist(dlist,1);
    insert_doublelinkedlist(dlist,5,3);
    traversal_doublelinkedlist(dlist);
    delete_node(dlist,3);
    traversal_doublelinkedlist(dlist);
    delete_node(dlist,5);
    traversal_doublelinkedlist(dlist);
    delete_node(dlist,1);
    traversal_doublelinkedlist(dlist);

}