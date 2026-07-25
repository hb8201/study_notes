// double linked list
#include<stdio.h>
#include<stdlib.h>

// 数据类型
struct dnode
{
    char data;              // 数据域
    struct dnode *prev;     // 指针域：前驱
    struct dnode *next;     // 指针域：后继
};
// 别名字
typedef struct dnode Node;
// 链表
typedef struct list
{
    Node *head;             // 头节点
    Node *tail;             // 尾指针
    int len;                // 大小（可选）
} List;


// 操作
void init(List *l);
Node *add(List *l, char data);
void show(List *l);
Node *get(List *l, int index);
Node *insert(List *l, int index, char ch);
void delete(List *l, int index);
int chaz(List *l, char ch);
void clean(List *l);
void fanz(List *l);
// 查找，清空，翻转

int main()
{
    List list;
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    show(&list);
    printf("%c\n", get(&list, 2)->data);
    insert(&list, 2, 'Z');
    show(&list);
    delete(&list, 3);
    show(&list);
    printf("%d\n", chaz(&list, 'A'));
    fanz(&list);
    show(&list);
    clean(&list);
    show(&list);
    return 0;
}

void init(List *l)
{
    // 头节点
    l->head = malloc(sizeof(Node));
    l->head->prev = NULL;
    l->head->next = NULL;
    // tail -> head
    l->tail = l->head;
    l->len = 0;
}

// O(1)
Node *add(List *l, char data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = l->tail;

    // 尾指针（原来的最后一个）的后继指向新节点
    l->tail->next = node;
    // 尾指针指向新节点
    l->tail = node;
    l->len++;
    return node;
}
// O(n)
void show(List *l)
{
    // 获得首元节点
    Node *node = l->head->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        // 获得后继节点
        node = node->next;
    }
    printf("\b}\n");
}
// O(n)
Node *get(List *l, int index)
{
    // TODO: 优化从尾指针往前遍历 if (index < l->len / 2)
    // index = 0
    Node *node = l->head->next;
    for (int i = 0; i < index; i++)
    {
        // 获得后继节点
        node = node->next;
    }
    return node;
}
// O(1)
Node *insert(List *l, int index, char ch)
{
    Node *cur = get(l, index);
    // 创建新节点
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->prev = cur->prev;
    node->next = cur;
    // 下面两行不能颠倒
    cur->prev->next = node;
    cur->prev = node;
    l->len++;

    return node;
}

void delete(List *l, int index)
{
    // 获得目标节点
    Node *node = get(l, index);
    //c跳过目标节点
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // 释放空间，避免空间泄漏
    free(node);
    l->len--;
}

int chaz(List *l, char ch)
{
    int i = 0, j = -1;
    Node *node = l->head->next;
    while (node != NULL)
    {
        if (node->data == ch)
        {
            j++;
            return i;
        }
        i++;
        node = node->next;
    }
    if (j == -1)
        return j;
}

void clean(List *l)
{
    Node *node1 = l->head->next;
    Node *node2 = NULL;
    while (node1 != NULL)
    {
        node2 = node1->next;
        free(node1);
        node1 = node2;
    }
    l->head->next = NULL;
    l->tail = l->head;
    l->len = 0;
}

void fanz(List *l)
{
    Node *a = l->head->next;
    Node *b = NULL;
    while (a != NULL)
    {
        b = a->next;
        a->next = a->prev;
        a->prev = b;
        a = b;
    }
    // a = l->head->next;
    // l->head->next = l->tail;
    // l->tail = a;
    // l->tail->next = NULL;
    
    l->tail = l->head->next;
    l->head->next = a;
}