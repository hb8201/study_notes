#include <stdio.h>
#include <stdlib.h>

typedef struct Node1
{
    char data;
    struct Node1 *next;
}Node;

typedef struct 
{
    Node *head;
    Node *r;
    int length;
} List;

void init(List *l);
void add(List *l, char ch);
void show(List *l);
void charu(List *l,int index, char ch);
void delete(List *l, int index);

int main()
{
    List list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);
    charu(&list, 1, 'w');
    show(&list);
    delete(&list, 2);
    show(&list);

    return 0;
}

void init(List *l)
{
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;
    l->r = l->head;
    l->length = 0;
}
void add(List *l, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = NULL;
    l->r->next = node;
    l->r = node;
    l->length++;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
    printf("长度：%d\n", l->length);
}

void charu(List *l,int index, char ch)
{
    Node *node1 = l->head;
    Node *node2 = l->head->next;
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    for (int i = 0; i < index; i++)
    {
        node1 = node1->next;
        node2 = node2->next;
    }
    node1->next = node;
    node->next = node2;
    l->length++;
}

void delete(List *l, int index)
{
    Node *node1 = l->head;
    Node *node2 = l->head->next;
    for (int i = 0; i < index; i++)
    {
        node1 = node1->next;
        node2 = node2->next;
    }
    node1->next = node2->next;
    l->length--;
}