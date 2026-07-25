/*
存储器层级	典型访问时间	介质	说明
CPU 寄存器	0.2–1 ns	触发器电路	最快，CPU 内部
L1 缓存	0.5–1.5 ns	SRAM	CPU 内核内
L2 缓存	3–8 ns	SRAM	CPU 片上
L3 缓存	8–20 ns	SRAM	多核共享
DDR5 内存	~60–120 ns	DRAM	主存
SSD (NVMe)	~10–100 μs	Flash	固态硬盘
机械硬盘 (HDD)	~5–15 ms	磁介质	含寻道 + 旋转延迟
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 19

typedef struct
{
    int *data;
    int len;
    int max;
} List;

void init(List *l);
void add(List *l, int data);
void show(List *l);

int main()
{
    List l;
    init(&l);
    add(&l, 2);
    add(&l, 13);
    add(&l, 7);
    add(&l, 26);
    add(&l, 83);
    add(&l, 55);
    add(&l, 48);
    add(&l, 73);
    add(&l, 25);
    add(&l, 3);
    add(&l, 8);
    add(&l, 43);
    add(&l, 77);
    add(&l, 90);
    add(&l, 57);
    add(&l, 92);
    add(&l, 45);
    add(&l, 56);
    add(&l, 93);
    add(&l, 22);
    show(&l);

    return 0;
}

void init(List *l)
{
    l->data = malloc(sizeof(int) * MAX);
    if (l->data == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    l->len = 0;
    l->max = MAX;
    for (int i = 0; i < l->max; i++)
    {
        l->data[i] = 0;
    }
}
void add(List *l, int data)
{
    if (l->len >= l->max * 0.7)
    {
        int new_max = (int)(l->max * 1.5);
        int *new_data = realloc(l->data, sizeof(int) * new_max);
        if (new_data == NULL)
        {
            perror("malloc failed");
            exit(1);
        }
        for (int i = l->max;i < new_max; i++)
        {
            new_data[i] = 0;
        }
        l->data = new_data;
        l->max = new_max;
    }
    int ha = data % 13;
    while (l->data[ha] != 0)
    {
        ha = (ha + 1) % l->max;
    }
    l->data[ha] = data;
    l->len++;
}
void show(List *l)
{
    for (int i = 0; i < l->max; i++)
    {
        if (l->data[i] != 0)
        {
            printf("%d:%d, ", i, l->data[i]);
        }
    }
}
