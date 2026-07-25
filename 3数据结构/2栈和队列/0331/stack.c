// stack.c
// 栈（顺序表）
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9

// 数据
typedef struct
{
    char data[MAX];     // 顺序表
    int top;            // 栈顶指针
} Stack;


// 操作
void init(Stack *s);
void push(Stack *s, char data);
char pop(Stack *s);
char top(Stack *s);
void clean(Stack *s);
bool empty(Stack *s);

int main()
{
    Stack stack;
    init(&stack);
    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C');
    push(&stack, 'D');
    printf("%c\n", top(&stack));
    printf("%c\n", top(&stack));

    while (!empty(&stack))
    {
        printf("%c,", pop(&stack));
    }


    return 0;
}

void init(Stack *s)
{
    s->top = -1;
}
void push(Stack *s, char data)
{
    if (s->top == MAX - 1)
        return;

    s->top++;
    s->data[s->top] = data;
}
char pop(Stack *s)
{
    if (s->top == -1)
        return EXIT_FAILURE;
    return s->data[s->top--];
}
char top(Stack *s)
{
    return s->data[s->top];
}
void clean(Stack *s)
{
    s->top = -1;
}
bool empty(Stack *s)
{
    return s->top == -1;
}
