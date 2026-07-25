// stack1.c
// 栈（链表）

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} Node, Stack;

void init(Stack *s);
void push(Stack *s, char ch);
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

    while (!empty(&stack))
    {
        printf("%c,", pop(&stack));
    }

    return 0;
}

void init(Stack *s)
{
    s->next = NULL;
}
void push(Stack *s, char ch)
{
    Node *node = malloc(sizeof(Node));
    node->data = ch;
    node->next = s->next;
    s->next = node;
}
char pop(Stack *s)
{
    Node *node = s->next;
    char ch = node->data;
    s->next = node->next;
    free(node);
    return ch;
}
char top(Stack *s)
{
    return s->next->data;
}
void clean(Stack *s)
{
    Node *node = s->next;
    while (node != NULL)
    {
        s->next = node->next;
        free(node);
        node = s->next;
    }
}
bool empty(Stack *s)
{
    return s->next == NULL;
}