// 实现函数void del_x(List *L,int x)删除链表中所有数据域值等于 x 的结点。
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, List;

void init(List *l);
void add(List *l, int data);
void show(List *l);
void del_x(List *l, int x);

int main()
{
    List list;
    init(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 2);
    add(&list, 6);
    show(&list);
    del_x(&list, 2);
    show(&list);
    return 0;
}
void init(List *l)
{
    l->next = NULL;
}
void add(List *l, int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = l->next;
    l->next = node;
}
void show(List *l)
{
    Node *node = l->next;
    printf("{");
    while (node != NULL)
    {
        printf("%d,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}
void del_x(List *l, int x)
{
    Node *node = l->next;
    Node *a = NULL;
    while (node != NULL)
    {
        if (node->data == x)
        {
            a->next = node->next;
            free(node);
            node = a->next;
            continue;
        }
        a = node;
        node = node->next;
    }
}