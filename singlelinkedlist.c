#include <stdio.h>
#include <stdlib.h>


typedef int elementType;

typedef struct NODE{
    elementType data;
    struct NODE *next;
}node;

node* initialize_linkedlist()
{
    node *head = (node*)malloc(sizeof(node));
    head -> next = NULL;
    head -> data = 114514;
    return head;
}


//头插法
void insert_head_method(node *l, int insert_text)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = insert_text;
    new_node -> next = l -> next;
    l -> next = new_node;
}

//尾插法
void insert_tail_method(node *l, int insert_text)
{
    node * new_node = (node*)malloc(sizeof(node));
    node *p = l;
    while(p->next!=NULL)
    {
        p = p -> next;
    }
    new_node -> next = p -> next;
    new_node -> data = insert_text;
    p -> next = new_node;
}

//任意位置插入 head0 1 2 3 4 ...
void insert_linkedlist(node *l, int insert_text, int position)
{
    node *new_insert = (node*)malloc(sizeof(node));
    node *p = l;
    for (int i=0;i<position;i++)
    {   
        if (p==NULL){
            return;
        }
        p = p -> next;
    }
    new_insert -> data = insert_text;
    new_insert -> next = p -> next;
    p -> next = new_insert;
    
}

//遍历
void read_linkedlist(node* l)
{   
    //printf("%d",l -> data);
    node *p = l -> next;
    while(p!=NULL)
    {
        printf("%d\n",p -> data);
        p = p -> next;
    }
    printf("\n");
}
int main()
{
    node* list = initialize_linkedlist();
    insert_head_method(list,810);
    insert_head_method(list,1919);
    insert_tail_method(list,114);
    insert_tail_method(list,514);
    read_linkedlist(list);
    printf("\n\n======\n\n");
    insert_linkedlist(list,114810,2);
    read_linkedlist(list);



    return 0;
}