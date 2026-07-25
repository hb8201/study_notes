// 二路归并排序     每相邻两个元素（小组）为一组进行比较
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data[20];
    int len;
} List;

void init(List *l);
void add(List *l, int data);
void show(List *l);
void paixu1(List *l, int index1, int index2);       // index1 第几个小数组   index2 每个小组有几个元素
void paixu2(List *l);

int main()
{   
    List l;
    init(&l);
    add(&l, 12);
    add(&l, 45);
    add(&l, 3);
    add(&l, 68);
    add(&l, 61);
    add(&l, 55);
    add(&l, 18);
    add(&l, 26);
    add(&l, 31);
    add(&l, 55);
    show(&l);
    paixu2(&l);
    show(&l);

    return 0;
}

void init(List *l)
{
    l->len = 0;
}
void add(List *l, int data)
{
    l->data[l->len] = data;
    l->len++;
}
void show(List *l)
{
    printf("{");
    for (int i = 0; i < l->len; i++)
    {
        printf("%d,", l->data[i]);
    }
    printf("\b}\n");
}
void paixu1(List *l, int index1, int index2)
{
    if (l->len == 1)
        return;
    int i = index1 * index2 + 1;
    for (int k = 1; k < index2; k++)
    {
        if (i >= l->len)
        return;
        int j = i - 1;
        int a = l->data[i++];
        int b = l->data[j];
        int c;
        while (a < b && j >= index1 * index2)
        {
            c = l->data[j + 1];
            l->data[j + 1] = l->data[j];
            l->data[j] = c;
            b = l->data[--j];
        }
    }
}
void paixu2(List *l)
{
    int d = (l->len + 1) / 2;         // 分为d个小组
    int w = 2;                        // 每个小组w个元素
    while (d > 0)
    {
        for (int i = 0; i < d; i++)
        {
            paixu1(l, i, w);
        }
        if (d == 1)
            return;
        d = (d + 1) / 2;
        w *= 2;
    }
}