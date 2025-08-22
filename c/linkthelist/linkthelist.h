#ifndef LINKTHELIST_H_
#define LINKTHELIST_H_ 

typedef struct _node{
    int value;
    struct _node *next;
} Node;

typedef struct _list{
    Node *head;
} List;

#endif