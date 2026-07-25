// circle_queue.c
// 循环队列：解决了假溢出
// 1. 空一格
// 2. 定义表示位
#include <stdio.h>
#include <stdlib.h>

#define MAX 6

// 结构体
typedef struct
{
    char data[MAX];     // 数据
    int front;          // 队首
    int rear;           // 队尾
    // int tag;         // 是否为空
} Queue;

// 操作：init, enqueue, dequeue, full, empty, show
void init(Queue *q);
int enqueue(Queue *q, char ch);
char dequeue(Queue *q);
int full(Queue *q);
int empty(Queue *q);
void show(Queue *q);
int size(Queue *q);

int main()
{
    Queue queue;
    init(&queue);
    enqueue(&queue, 'A');
    enqueue(&queue, 'B');
    enqueue(&queue, 'C');
    enqueue(&queue, 'D');
    enqueue(&queue, 'E');
    enqueue(&queue, 'F');
    show(&queue);
    printf("%c\n", dequeue(&queue));
    printf("%c\n", dequeue(&queue));
    printf("%c\n", dequeue(&queue));

    show(&queue);
    enqueue(&queue, 'X');
    enqueue(&queue, 'Y');
    enqueue(&queue, 'Z');
    show(&queue);
   return 0;
}

void init(Queue *q)
{
    q->rear = 0;
    q->front = 0;
}
int full(Queue *q)
{
    // 队尾回头
    return (q->rear + 1) % MAX == q->front;
}
int empty(Queue *q)
{
    return q->rear == q->front;
}
int size(Queue *q)
{
    return (q->rear - q->front + MAX) % MAX;
}
int enqueue(Queue *q, char ch)
{
    if (full(q))
        return 0;
    // 回头
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = ch;
}
char dequeue(Queue *q)
{
    if (empty(q))
        return EXIT_FAILURE;
    // 回头
    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}
void show(Queue *q)
{
    int len = size(q);
    printf("{");
    for (int i = 0; i < len; i++)
    {
        int index = (q->front + 1 + i) % MAX;
        printf("%c,", q->data[index]);
    }
    printf("\b}\n");
}