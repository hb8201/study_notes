// 希尔排序
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
void paixu1(List *l, int index1, int index2);    // 直接插入排序    index1 第几个小数组   index2 每隔几个排序
void paixu2(List *l);   // 希尔排序

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
    for (int i = index1 + index2; i < l->len;)
    {
        int j = i - index2;
        int a = l->data[i];
        int b = l->data[j];
        int c;
        while (a < b && j >= 0)
        {
            c = l->data[j + index2];
            l->data[j + index2] = l->data[j];
            l->data[j] = c;
            j -= index2;
            b = l->data[j];
        }
        i += index2;
    }
}
void paixu2(List *l)
{
    int d = l->len / 2;     // 将数组分为d个小数组
    while (d != 0)
    {
        for (int i = 0; i < d; i++)
        {
            paixu1(l, i, d);
        }
        d /= 2;
    }
}