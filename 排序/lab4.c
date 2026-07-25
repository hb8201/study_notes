// 冒泡排序             将相邻元素两两比较，大的往后冒出，每一轮把往前最大放到末尾
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
    for (int i = l->len - 1; i >= 0; i--)
    {
        int t;
        for (int j = 0; j < i; j++)
        {
            if (l->data[j] > l->data[j + 1])
            {
                t = l->data[j];
                l->data[j] = l->data[j + 1];
                l->data[j + 1] = t;
            }
        }
    }
}