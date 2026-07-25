// 二路归并(数组)
#include <stdio.h>
#include <stdlib.h>

int w = 10;

typedef struct
{
    int *data;
    int len;
}List;

void init(List *l);
void add(List *l, int n);
void hebing(List *l1, List *l2, List *l3);
void show(List *l);

int main()
{
    List l1, l2, l3;
    init(&l1);
    add(&l1, 1);
    add(&l1, 3);
    add(&l1, 5);
    add(&l1, 7);
    add(&l1, 9);
    init(&l2);
    add(&l2, 0);
    add(&l2, 2);
    add(&l2, 4);
    add(&l2, 6);
    add(&l2, 8);
    init(&l3);
    hebing(&l1, &l2, &l3);
    show(&l1);
    show(&l2);
    show(&l3);

    return 0;
}

void init(List *l)
{
    l->data = malloc(sizeof(int) * w);
    l->len = 0;
}
void add(List *l, int n)
{
    if (l->len == w)
    {
        w *= 2;
        l->data = realloc(l->data, sizeof(int) * w);
    }
    l->data[l->len] = n;
    l->len++;
}

void hebing(List *l1, List *l2, List *l3)
{
    int i=0, j=0, k = 0;
    l3->data = malloc(sizeof(int) * (l1->len + l2->len));
    while (1)
    {
        if (i == l1->len || j == l2->len)
            break;
        if (l1->data[i] < l2->data[j])
        {
            l3->data[k] = l1->data[i];
            k++;
            i++;
            l3->len++;
        }
        else
        {
            l3->data[k] = l2->data[j];
            k++;
            j++;
            l3->len++;
        }
    }

    while (i != l1->len)
    {
        l3->data[k] = l1->data[i];
        k++;
           i++;
        l3->len++;
       }

    while (j != l2->len)
    {
       l3->data[k] = l2->data[j];
        k++;
        j++;
        l3->len++;
    }
}

void show(List *l)
{
    printf("{");
    for (int i = 0; i < l->len; i++)
        printf("%d,", l->data[i]);
    printf("\b}\n");
}