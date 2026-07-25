// 元素去重
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
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
void hebing(List *l1, List *l2, List *l3);
void quchong(List *l);

int main()
{
    List list1;
    List list2;
    List list3;
    init(&list1);
    add(&list1, 1);
    add(&list1, 2);
    add(&list1, 3);
    add(&list1, 4);
    add(&list1, 5);
    show(&list1);
    init(&list2);
    add(&list2, 1);
    add(&list2, 3);
    add(&list2, 5);
    add(&list2, 7);
    add(&list2, 9);
    show(&list2);
    init(&list3);
    hebing(&list1, &list2, &list3);
    show(&list3);
    quchong(&list3);
    show(&list3);

    return 0;
}

void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    l->tail = l->head;
    l->len = 0;
}
void add(List *l, int n)
{
    Node *node = malloc(sizeof(Node));
    node->data = n;
    node->next = NULL;
    l->tail->next = node;
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
void hebing(List *l1, List *l2, List *l3)
{
    Node *node1 = l1->head->next;
    Node *node2 = l2->head->next;
    while (node1 != NULL && node2 != NULL)
    {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        if (node1->data < node2->data)
        {
            node->data = node1->data;
            node1 = node1->next;
        }
        else
        {
            node->data = node2->data;
            node2 = node2->next;
        }
        l3->tail->next = node;
        l3->tail = node;
        l3->len++;
    }

    while (node1 != NULL)
    {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        node->data = node1->data;
        l3->tail->next = node;
        l3->tail = node;
        l3->len++;
        node1 = node1->next;
    }

    while (node2 != NULL)
    {
        Node *node = malloc(sizeof(Node));
        node->next = NULL;
        node->data = node2->data;
        l3->tail->next = node;
        l3->tail = node;
        l3->len++;
        node2 = node2->next;
    }
}
void quchong(List *l)
{
    Node *node1 = l->head->next;
    Node *node2 = node1->next;
    while (node2 != NULL)
    {
        if (node1->data == node2->data)
        {
            node1->next = node2->next;
            free(node2);
            l->len--;
            node2 = node1->next;
        }
        else
        {
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    l->tail = node1;
}