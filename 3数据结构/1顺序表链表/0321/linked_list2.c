// linked list2
// 尾插法实现单链表
#include <stdio.h>
#include <stdlib.h>

// 节点
struct node
{
    char data;              // 数据域
    struct node *next;      // 指针域：后继
};

typedef struct node Node;

typedef struct linkedlist
{
    Node *head;      // 头节点
    Node *r;         // 尾指针
    int length;             // 链表大小
} LinkedList;

void init(LinkedList *l);
void add(LinkedList *l, char ch);
void show(LinkedList *l);
// 插入，删除，查找，清空

int main()
{
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
    // 创建头节点
    l->head = malloc(sizeof(Node));
    // 空表
    l->head->next = NULL;
    // 尾指针指向头节点
    l->r = l->head;
    l->length = 0;
}
void add(LinkedList *l, char ch)
{
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = NULL;
    // 最后一个元素的后继指向新节点
    l->r->next = node;
    // 尾指针指向新节点
    l->r = node;
    //
    l->length++;
}
void show(LinkedList *l)
{
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        // 获得下一个节点
        node = node->next;
    }
    printf("\b}\n");
    printf("%d\n", l->length);
}