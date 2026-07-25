// linked_list3                 尾插法
#include <stdio.h>
#include <stdlib.h>

// 定义节点（数据元素）
typedef struct node
{
    char data;              // 数据域
    struct node *next;      // 指针域
} Node;

// 定义链表：头节点（哨兵节点）和尾指针
typedef struct list
{
    Node *head;         // 头节点，创建
    Node *tail;         // 尾指针，空表指向头节点，非空表指向最后一个节点
} List;

// 操作
// list.h
void init(List *l);
Node *add(List *l, char data);
void show(List *l);
Node *get(List *l, int index);
Node *insert(List *l, int index, char data);
void delete(List *l, int index);
// 查找，返回下标，找不到返回 -1
int find(List *l, char data);
// 清空
void clean(List *l);
// 翻转链表
void reverse(List *l);

//
int main()
{
    List list;
    init(&list);
    show(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);
    Node *n = get(&list, 1);
    // printf("%c", get(&list, 0)->data);
    // printf("%c", get(&list, 1)->data);
    // printf("%c", get(&list, 2)->data);
    // printf("%c", get(&list, 3)->data);
    insert(&list, 1, 'Z');
    show(&list);
    delete(&list, 2);
    show(&list);
    printf("%d\n", find(&list, 'D'));
    printf("%d\n", find(&list, 'W'));
    reverse(&list);
    show(&list);
    clean(&list);
    show(&list);
    return 0;
}

// list.c
void init(List *l)
{
    // 创建头节点
    l->head = malloc(sizeof(Node));
    l->head->next = NULL;               // 空表 NULL，否则指向首元节点
    // 设置尾指针
    l->tail = l->head;                  // 尾指针指向头节点：空表
}
// O(1)
Node *add(List *l, char data)
{
    // 动态分配的堆空间，函数结束不释放，直到 free()
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;

    // 最后一个元素的后继指向新节点，然后尾指针指向新节点
    l->tail->next = node;
    l->tail = node;

    return node;
}
void show(List *l)
{
    Node *node = l->head->next;
    printf("{");
    // while (node)
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}
// O(n)
Node *get(List *l, int index)
{
    // node -> 首元
    Node *node = l->head->next;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}
// O(1)
Node *insert(List *l, int index, char data)
{
    // 获得插入点的前驱节点
    Node *prev = get(l, index - 1);
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = data;
    // 新节点的后继指向原来的 index
    node->next = prev->next;
    // 前一个指向新节点
    prev->next = node;
    return node;
}
// O(1)
void delete(List *l, int index)
{
    // 获得删除位置的前驱节点
    Node *prev = get(l, index - 1);
    // 获得目标节点
    Node *node = prev->next;
    // 跳过目标节点
    prev->next = prev->next->next;
    // 释放堆空间，避免内存泄露
    free(node);
}
// O(n)
int find(List *l, char data)
{
    int a = 0;
    Node *node = l->head->next;
    while (node != NULL)
    {
        if (node->data == data)
            return a;
        else
        {
            a++;
            node = node->next;
        }
    }
    return -1;
}
// O(n)
void clean(List *l)
{
    Node *node = l->head->next;
    Node *node1;
    while (node != NULL)
    {
        node1 = node->next;
        free(node);
        node = node1;
    }
    l->head->next = NULL;
    l->tail = l->head;
}
// O(n)
void reverse(List *l)
{
    Node *a = NULL;
    Node *b = l->head->next;
    Node *c = NULL;

    if (l == NULL || l->head->next == NULL || l->head->next->next == NULL)
        return;

    while (b != NULL)
    {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    // 保留首元
    Node *first = l->head->next;
    // 头节点指向原来的最后一个节点
    l->head->next = a;
    // 尾指针指向原来的首元
    l->tail = first;
    // 或者
    // l->tail = l->head->next;
    // l->head->next = a;
}