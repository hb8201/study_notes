// 动态顺序表
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 3

typedef int ElemType;

typedef struct List
{
    ElemType *data;     // 容器
    int length;         // 长度
    int capacity;       // 容量
} List;

//
void init(List *l);
void add(List *l, ElemType e);
void grow(List *l);

int main()
{
    List list;
    init(&list);
    for (int i = 0; i < 20; i++)
    {
        add(&list, i);
    }

    return 0;
}

void init(List *l)
{
    l->capacity = INIT_SIZE;
    l->data = malloc(sizeof(ElemType) * INIT_SIZE);
    l->length = 0;
}

void grow(List *l)
{
    // 扩容
    // 1. 增长因子, +n
    // 2. 增加 2倍 或 1.5倍
    // n << 1   *2
    // n >> 1   /2
    int grow = l->capacity;
    // int grow = l->capacity >> 1;
    l->capacity += grow;
    l->data = realloc(l->data, sizeof(ElemType) * l->capacity);
    if (l->data == NULL)
    {
        printf("扩容失败\n");
        return;
    }
    printf("扩容至：%d\n", l->capacity);
}

void add(List *l, ElemType e)
{
    if (l->length == l->capacity)
        grow(l);
    l->data[l->length++] = e;
}