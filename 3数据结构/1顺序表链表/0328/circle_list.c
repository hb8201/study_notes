// circle linkde list
// 循环链表
// 循环单链表、循环双链表
#include <stdio.h>
#include <stdlib.h>

// 数据
typedef struct node
{
    char data;              // 数据域
    struct node *next;      // 指针域
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} List;

// 操作
void init(List *l);
Node *add(List *l, char ch);
void show(List *l);

int main()
{
    List list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);

    return 0;
}
void init(List *l)
{
    l->head = malloc(sizeof(Node));             // 注意记得分配空间
    if (l->head == NULL)
        return;
    l->head->next = l->head;
    l->tail = l->head;
}
Node *add(List *l, char ch)
{
    // 尾插法
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = l->head;       // 指向头节点，形成循环
    // 新节点成为最后一个节点的后继
    l->tail->next = node;
    // 尾指针指向新节点
    l->tail = node;
    return node;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;

        if (node == l->head)
            break;
    }
    printf("\b}\n");
}
