// 给定一个无序整型数组，用大顶堆实现升序排序，输出排序后的数组
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct 
{
    int data[MAX];
    int len;
} List;

void init(List *l);
void add(List *l, int data);
int paixu(List *l);

int main()
{
    List list;
    int x = 0;
    int a[MAX];
    init(&list);
    add(&list, 32);
    add(&list, 12);
    add(&list, 45);
    add(&list, 84);
    add(&list, 92);
    add(&list, 37);
    add(&list, 26);
    add(&list, 66);
    add(&list, 83);
    add(&list, 22);
    printf("{");
    while (list.len != 0)
    {
        a[x] = paixu(&list);
        x++;
    }
    x = x - 1;
    while (x >= 0)
    {
        printf("%d,",a[x--]);
    }
    printf("\b}\n");
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
int paixu(List *l)
{
    int a = (l->len - 1) / 2;
    int t;
    for (int i = a; i >= 0; i--)
    {
        int b = 2 * i + 1; // 左
        int c = 2 * i + 2; // 右
        if (c < l->len && l->data[b] <= l->data[c])
        {
            if (l->data[i] <= l->data[c])
            {
                t = l->data[i];
                l->data[i] = l->data[c];
                l->data[c] = t;
            }
        }
        else if (l->data[b] >= l->data[c])
        {
            if (l->data[b] >= l->data[i])
            {
                t = l->data[b];
                l->data[b] = l->data[i];
                l->data[i] = t;
            }
        }
    }
    int w = l->data[0];
    l->data[0] = l->data[l->len - 1];
    l->len--;
    return w;
}