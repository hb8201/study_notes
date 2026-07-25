// 直接插入排序         将未排序区域的第一个元素插入到已排序元素中
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
    if (l->len == 1)
        return;
    for (int i = 1; i < l->len; i++)
    {
        int j = i - 1;
        int a = l->data[i];
        int b = l->data[j];
        int c;
        while (a < b && j >= 0)
        {
            c = l->data[j + 1];
            l->data[j + 1] = l->data[j];
            l->data[j] = c;
            b = l->data[--j];
        }
    }
}