// fun.c
// 函数
#include <stdio.h>
#include <stdbool.h>
// #include <math.h>
// #include <string.h>
// #include <ctype.h>
// 当前路径的自定义头文件
// 模块化：高内聚、低耦合
// KISS: Keep It Simple Stupid 让事物尽可能简洁     单一任务原则
#include "my.h"

// 函数声明
// void printf_array(int x[], int len);

bool is_prime(int n)
{
    // 标识符
    bool flag = true;
    // 2~n的平方根
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

// 程序的入口
int main()
{
    // int a[] = {100, 200, 300, 400, 500};
    // int b[20] = {0};
    // int c[20] = {0};
    // // DRY = Do'n't Repeat Yourself 不要重复自身
    // // 函数调用
    // printf_array(a, 5);     // x = a, len = 5;
    // printf_array(b, 20);    // 实际参数
    // printf_array(c, 20);

    for (int i = 2, c = 0; c < 100; i++)
    {
        if (is_prime(i))
        {
            printf("%d,", i);
            c++;
        }
    }

    return 0;
}