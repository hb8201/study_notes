// 单链表逆序（翻转）
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
void fanzhuan(List *l);

int main()
{
    List list;
    init(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    add(&list, 6);
    show(&list);
    fanzhuan(&list);
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
void fanzhuan(List *l)
{
    Node *a = l->next;
    Node *b = NULL;
    Node *c;
    while (a != NULL)
    {
        c = a->next;
        a->next = b;
        b = a;
        a = c;
    }
    l->next = b;
}