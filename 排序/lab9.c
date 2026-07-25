// 基数排序         一位一位地排序
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int data[MAX];
    int front;
    int rear;

} Queue;

void init(Queue *q);
int max_wei(int *data);                 // 获取最大位数
int wei(int data1, int data2);          // 获取数data1中第data2位的值    位数判断，从右到左 1为个位，2为十位
void paixu(Queue *q, int *data);
void show(int *data);

int main()
{
    int sum[MAX] = {2381,3842,9645,3895,4859,1290,4389,6659,3956,7845};
    Queue q[10];
    init(q);
    paixu(q, sum);
    show(sum);

    return 0;
}

void init(Queue *q)             // ⚠️ 因为是队列数组，所以要给每一个数组中的队列的头尾初始化
{
    for (int i = 0; i < 10; i++)
    {
        q[i].front = -1;
        q[i].rear = -1;
    }
}
int max_wei(int *data)
{
    int d[MAX];
    int max = 0;
    for (int i = 0; i < MAX; i++)
    {
        d[i] = data[i];
        int a = 0;
        while (d[i] != 0)
        {
            d[i] /= 10;
            a++;
        }
        if (max < a)
            max = a;
    }
    return max;
}
int wei(int data1, int data2)
{
    int i = 1;
    while (1)
    {
        if (i == data2)
            return data1 % 10;
        data1 /= 10;
        i++;
    }
}
void paixu(Queue *q, int *data)
{
    int a = 1;      // 数的位数
    int m = max_wei(data);     // 获取数组中数的最大位数
    while (1)
    {
        for (int i = 0; i < MAX; i++)   // 将数组里的数按照第 a 位的值放到对应队列里
        {
            int b = wei(data[i], a);
            q[b].data[++q[b].rear] = data[i];
        }
        for (int i = 0, j = 0; i < MAX; i++)  // 将队列中的数依次取出放到数组里
        {
            while (q[i].rear != q[i].front)
            {
                data[j++] = q[i].data[++q[i].front];
            }
            q[i].front = -1;            // ⚠️ 用完队列后要给他初始化，以便循环使用
            q[i].rear = -1;
        }
        a++;
        if (a > m)
            return;
    }
}
void show(int *data)
{
    printf("{");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d,", data[i]);
    }
    printf("\b}\n");
}