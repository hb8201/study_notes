// 3．栈实现括号匹配
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char data[20];
    int top;
} Stack;

void init(Stack *s);
void add(Stack *s, char str);

int main()
{
    Stack stack;
    return 0;
}
void init(Stack *s)
{
    s->top = -1;
}
void add(Stack *s, char str)
{
    s->top++;
    s->data[s->top] = str;
}