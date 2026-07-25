// 简单选择排序     在未排序区域内找到最小的放在未排序的第一位
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
void paixu(List *l);

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
    paixu(&l);
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
void paixu(List *l)
{
    for (int i = 0; i < l->len - 1; i++)
    {
        int min = l->data[i];
        int a, t;
        for (int j = i + 1; j < l->len; j++)
        {
            if (min > l->data[j])
            {
                min = l->data[j];
                a = j;
            }
        }
        t = l->data[i];
        l->data[i] = l->data[a];
        l->data[a] = t;
    }
}