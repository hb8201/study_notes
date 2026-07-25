// ptr.c
#include <stdio.h>

int main()
{
    // int a = 42;
    // int *p = NULL;      // 初始化为空指针（0）
    // printf("%p\n", p);

    // p = &a;
    // if (p != NULL)
    // {
    //     printf("p = %d\n", *p);
    // }

    // 指针与数组
    // 数组：复合/组合数据类型
    // char ch[] = {'h', 'e', 'l', 'l', 'o'};
    // char *p = ch;
    // while (p < ch + 5)
    // {
    //     printf("%c\n", *p);
    //     p++;
    // }

    // ch++      错误
    // char *p = ch;
    // printf("%c\n", *p);
    // p++;
    // printf("%c\n", *p);

    // long ch[5] = {0};

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%ld\n", *(ch + i));
    // }

    // int ch[9] = {0};
    // int *p = NULL;

    // 一下三种赋值对于数组来说都一样，通常用第一种
    // p = ch;
    // p = &ch;
    // p = &ch[0];

    // for (int i = 0; i < 9; i++)
    // {
    //     printf("%d, %d, %p\n", i, ch[i], &ch[i]);
    // }

    // printf("%x, %x, %x\n", ch, &ch, &ch[0]);

    return 0;
}