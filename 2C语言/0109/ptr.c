// ptr.c
#include <stdio.h>

// 全局变量
int r;

// 指针函数
int *f(int a, int b, int *r)
{
    *r = a + b;  // 局部变量
    // return &r;   // 错误的
    // int *p = &r; // 错误的
    // return p;    // 错误的
    return r;
}

// max(int a[], int len)
void max(int *a, int len, int *r)
{
    // *r = *a;
    // for (int i = 1; i < len; i++)
    // {
    //     if (*r < *(a + i))
    //         *r = *(a + i);
    // }

    // *r = a[0];
    // for (int i = 1; i < len; i++)
    // {
    //     if (a[i] > *r)
    //         *r = a[i];
    // }

    // 基于指针访问
    // int max = *a;
    // for (int i = 1; i < len; i++)
    // {
    //     if (max < *(a + i))
    //         max = *(a + i);
    // }

    // 基于下标访问
    // int max = a[0];
    // for (int i = 1; i < len; i++)
    // {
    //     if (a[i] > max)
    //         max = a[i];
    // }
    // return r;
}

int main()
{
    int m[] = {12, 2, 42, 9, 5, 23, 7};
    int size = sizeof(m) / sizeof(m[0]);
    // int r = max(m, size);
    int r;
    // 面向过程的程序设计思维方式
    // IN, OUT
    max(m, size, &r);
    printf("%d\n", r);


    // int a = 1;
    // int b = 2;
    // int r;

    // int *p = f(a, b, &r);

    // printf("%p, %d\n", &r, r);
    // printf("%p\n", p);
    return 0;
}