// 判断单链表是否是回文
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
    int len;
} List;

void init(List *l);
void add(List *l, int n);
void show(List *l);
void huiwen(List *l);

int main()
{
    List list;
    init(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    add(&list, 4);
    add(&list, 3);
    add(&list, 2);
    add(&list, 1);
    // add(&list, 0);
    show(&list);
    huiwen(&list);

    return 0;
}

void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    l->head->prev = NULL;
    l->tail = l->head;
    l->len = 0;
}
void add(List *l, int n)
{
    Node *node = malloc(sizeof(Node));
    node->data = n;
    node->next = NULL;
    l->tail->next = node;
    node->prev = l->tail;
    l->tail = node;
    l->len++;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%d,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}
void huiwen(List *l)

{
    int i = 0, j = 1;
    Node *node1 = l->head->next;
    Node *node2 = l->tail;
    while (i < l->len / 2)
    {
        if (node1->data != node2->data)
            j = 0;
        node1 = node1->next;
        node2 = node2->prev;
        i++;
    }
    if (j)
        printf("YES\n");
    else
        printf("NO\n");
}