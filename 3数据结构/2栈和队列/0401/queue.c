// queue.c
// 队列
#include <stdio.h>
#include <stdlib.h>

#define MAX 6

// 结构体
typedef struct
{
    char data[MAX];     // 数据
    int front;          // 队首
    int rear;           // 队尾
} Queue;

// 操作：init, enqueue, dequeue, full, empty, show
void init(Queue *q);
void enqueue(Queue *q, char ch);
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
    show(&queue);
    printf("%c\n", dequeue(&queue));
    printf("%c\n", dequeue(&queue));
    show(&queue);
   return 0;
}
void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
void enqueue(Queue *q, char ch)
{
    if (full(q))
        return;
    q->rear++;
    q->data[q->rear] = ch;
}
char dequeue(Queue *q)
{
    if (empty(q))
        return EXIT_FAILURE;
    q->front++;
    return q->data[q->front];
}
int full(Queue *q)
{
    return q->rear == MAX - 1;
}
int empty(Queue *q)
{
    return q->front == q->rear;
}
void show(Queue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%c,", q->data[i]);
    }
    printf("\n");
}
int size(Queue *q)
{
    return q->rear - q->front;
}