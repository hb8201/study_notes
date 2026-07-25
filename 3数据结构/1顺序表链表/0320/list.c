// list.c
// 静态顺序表
#include <stdio.h>
#include <stdbool.h>

// 表的容量，静态表
#define MAX 16

// ADT 表是容器
typedef struct
{
    char data[MAX];     // 表的容量
    // char *data2;
    int length;         // 表的大小
} List;

// 声明操作
void init(List *l);
void add(List *l, char ch);
void show(List *l);
void insert(List *l, int n, char ch);
char get(List *l, int index);
int find(List *l, char ch);
bool empty(List *l);
void clean(List *l);
char delete(List *l, int index);

int main()
{
    List list;
    // printf("%ld\n", sizeof(list));
    init(&list);
    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');
    add(&list, 'D');
    add(&list, 'E');
    show(&list);
    insert(&list, 1, 'Z');
    show(&list);
    char ch = get(&list, 3);
    printf("%c\n", ch);
    
    printf("%d\n", find(&list, 'D'));
    printf("%d\n", find(&list, 'F'));

    printf("%c\n", delete(&list, 1));
    show(&list);

    return 0;
}

// 定义
void init(List *l)
{
    // l->data2 = (char *)malloc(sizeof(MAX));
    l->length = 0;
}
void add(List *l, char ch)
{
    if (l->length == MAX)
    {
        perror("满了\n");
        return;
    }

    l->data[l->length] = ch;
    l->length++;
}
void show(List *l)
{
    printf("{");
    for (int i = 0; i < l->length; i++)
    {
        printf("%c, ", l->data[i]);
    }
    printf("\b\b}\n");          // \b 转义字符，回退
}
// O(n)
void insert(List *l, int n, char ch)
{
    // 边界判断
    // 移动 l->length
    for (int i = l->length - 1; i >= n; i--)
    {
        l->data[i + 1] = l->data[i];
    }
    // 插入
    l->data[n] = ch;
    l->length++;
}
// O(1)
char get(List *l, int index)
{
    // if (index >= l->length)
    //     return;
    return l->data[index];
}
// O(n)
int find(List *l, char ch)
{
    int index = -1;
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] == ch)
        {
            index = i;
            break;
        }
    }
    return index;
}
bool empty(List *l)
{
    return l->length == 0;
}
void clean(List *l)
{
    l -> length = 0;
}
// O(n)
char delete(List *l, int index)
{
    char ch = l->data[index];
    for (int i = index + 1; i < l->length; i++)
    {
        l->data[i - 1] = l->data[i];
    }
    l->length--;
    return ch;
}
