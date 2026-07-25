#include <stdio.h>
#include <stdlib.h>

typedef struct Listt
{
    char data;
    struct Listt *next;
}Node, List;

void init(List *l);
void add(List *l, char ch);
void show(List *l);
void charu(List *l, int n, char ch);
void delete(List *l, int index);
void cha1(List *l, int index);
void cha2(List *l, char ch);

int main()
{
    List list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);
    charu(&list, 1, 'W');
    show(&list);
    delete(&list, 3);
    show(&list);
    cha1(&list, 2);
    cha2(&list, 'A');

    return 0;
}

void init(List *l)
{
    l-> next = NULL;
}
void add(List *l, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->next;
    l->next = node;
}
void show(List *l)
{
    Node *node = l->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}

void charu(List *l, int n, char ch)
{
    Node *node1 = l->next;
    Node *node2 = malloc(sizeof(Node));
    node2->data = ch;
    for (int i = 1; i < n; i++)
    {
        node1 = node1->next;
    }
    node2->next = node1->next;
    node1->next = node2;
}

void delete(List *l, int index)
{
    char c;
    Node *node1 = l->next;
    Node *node2 = node1->next;
    for (int i = 1; i < index; i++)
    {
        node1 = node1->next;
        node2 = node2->next;
    }
    c = node2->data;
    node1->next = node2->next;
    printf("删除%c\n", c);
}
void cha1(List *l, int index)
{
    Node *node = l->next;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    if (node != NULL)
        printf("%c\n", node->data);
    else
        printf("输入的下标超出链表范围，无法查找\n");
}
void cha2(List *l, char ch)
{
    int a = 0, b = 0;
    Node *node = l->next;
    while (node->next != NULL)
    {
        a++;
        node = node->next;
        if (node->data == ch)
        {
            printf("%d\n", a);
            b = 1;
            break;
        }
    }
    if (b == 0)
        printf("没有\n");
}