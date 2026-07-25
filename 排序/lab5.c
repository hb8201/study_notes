// 快速排序     先定义一个基准，比基准大的放基准后面，小的放前面，然后对两个区域递归
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
List *paixu(List *l, int index1, int index2);    // index1 数组起始下标     index2 数组末尾下标

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
    paixu(&l, 0, l.len - 1);
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
List *paixu(List *l, int index1, int index2)
{
    int A = l->data[index1];    // 基准的值
    int L = index1 + 1;         // 左指针指向的下标
    int R = index2;             // 右指针指向的下标
    int t;
    if (index1 >= index2)
        return l;
    while (L < R)
    {
        while (L < R && l->data[L] <= A)
        {
            L++;
        }
        while (L < R && l->data[R] >= A)
        {
            R--;
        }
        if (L < R)
        {
            t = l->data[L];
            l->data[L] = l->data[R];
            l->data[R] = t;
        }
    }
    if (l->data[L] > A)
    {
        t = l->data[index1];
        l->data[index1] = l->data[L - 1];
        l->data[L - 1] = t;
        paixu(l, index1, L - 2);
        paixu(l, L, index2);
    }
    else
    {
        t = l->data[index1];
        l->data[index1] = l->data[L];
        l->data[L] = t;
        paixu(l, index1, L - 1);
        paixu(l, L + 1, index2);
    }
    return l;
}