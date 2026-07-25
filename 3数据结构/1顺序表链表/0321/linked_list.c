// linked list
// 头插法实现单链表
#include <stdio.h>
#include <stdlib.h>

// 节点
typedef struct node
{
    char data;              // 数据域
    struct node *next;      // 指针域：后继
} Node, LinkedList;

void init(LinkedList *l);

void add(LinkedList *l, char ch);
void show(LinkedList *l);
// 插入、删除、查找         实现

int main()
{
    // 头节点
    LinkedList list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);

    return 0;
}

void init(LinkedList *l)
{
    // 空表：头节点后继为空
    l->next = NULL;
}
void add(LinkedList *l, char ch)
{
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->next;
    // 头节点指向新节点
    l->next = node;
}
void show(LinkedList *l)
{
    // 首元节点
    Node *node = l->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}