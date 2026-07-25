// queue_list.c
// 队列（链表）
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} Node;
typedef struct queue
{
    Node *rear;     // 队尾：入队
    Node *front;    // 队首：出对
    int len;
} Queue;

void init(Queue *q);
void enqueue(Queue *q, char ch);
char dequeue(Queue *q);
int empty(Queue *q);
void show(Queue *q);

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
    printf("%d\n", empty(&queue));
    show(&queue);
    printf("%c\n", dequeue(&queue));
    printf("%c\n", dequeue(&queue));
    printf("%c\n", dequeue(&queue));
    printf("%d\n", empty(&queue));
    show(&queue);

    return 0;
}

void init(Queue *q)
{
    q->front = malloc(sizeof(Node));
    q->front->next = NULL;
    q->rear = q->front;
    q->len = 0;
}
void enqueue(Queue *q, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    q->len++;
}
char dequeue(Queue *q)
{
    if (q->len == 0)
        return EXIT_FAILURE;
    Node *node = q->front->next;
    char ch = node->data;
    q->front->next = node->next;
    q->len--;
    free(node);
    return ch;
}
int empty(Queue *q)
{
    return !q->len;
}
void show(Queue *q)
{
    Node *node = q->front->next;
    printf("{");
    while (node != NULL)
    {
        printf("%c,", node->data);
        node = node->next;
    }
    printf("\b}\n");
}
