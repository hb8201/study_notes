// 堆排序
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
    List L = *l;
    int t, w = 0;
    while (L.len)
    {
        int a = (L.len - 1) / 2;       // 最后一个根节点下标
        for (int i = a; i >= 0; i--)
        {
            if (((2 * i + 2) < L.len) && L.data[2 * i + 1] >= L.data[2 * i + 2])
            {
                if (L.data[2 * i + 2] <= L.data[i])
                {
                    t = L.data[i];
                    L.data[i] = L.data[2 * i + 2];
                    L.data[2 * i + 2] = t;
                }
            }
            else if(L.data[2 * i + 1] <= L.data[2 * i + 2])
            {
                if (L.data[2 * i + 1] <= L.data[i])
                {
                    t = L.data[i];
                    L.data[i] = L.data[2 * i + 1];
                    L.data[2 * i + 1] = t;
                }
            }
        }
        l->data[w++] = L.data[0];
        L.data[0] = L.data[L.len - 1];
        L.len--;
    }
}
