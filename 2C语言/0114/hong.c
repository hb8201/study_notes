// 宏
#include <stdio.h>
#include "my.h"

// 宏名称
#define PI 3.1415        // 简单宏
#define C(r) 2 * PI *(r) // 带参数的宏 参数要单独用括号括起来
#define MUL(a, b) (a) * (b)
// 参数无类型：解决了函数不能重载的问题
#define MAX(a, b) (a) > (b) ? (a) : (b)
// # 转换成字符串
// #define STR(x) #x
#define TO_STR(x) #x
#define STR(x) TO_STR(x)
// ## 拼接字符串a, b
#define CAT(a, b) a##b

// 函数**重载**
// int max(int x, int y)
// {
//     return x > y ? x : y;
// }
// double max(double x, double y)
// {
//     return x > y ? x : y;
// }
// char max(char x, char y)
// {
//     return x > y ? x : y;
// }

double c1(int r)
{
    return 2 * PI * r;
}

int main()
{
    printf("%d\n", max(2,3));
    printf("%d\n", N);

    // int num1 = 100;
    // int num2 = 200;
    // int num3 = 300;
    // printf("%d\n", CAT(num, 1));
    // printf("%d\n", CAT(num, 2));
    // printf("%d\n", CAT(num, 3));

    // int a = 2;
    // int b = 3;
    // // printf("%d + %d = %d\n", a, b, a + b);
    // printf("%s = %d\n", STR(a + b), a + b);
    // printf("%s\n", STR(PI));

    // printf("%d\n", max(2, 5));
    // printf("%f\n", MAX(23.055, 52.36));
    // printf("%c\n", max('B', 'c'));

    // 2 * PI * R
    // int r = 5;
    // printf("%f\n", 2 * PI * r); // 表达式
    // printf("%f\n", C(r + 1));   // 宏
    // printf("%f\n", c1(r + 1));  // 函数
    // printf("%d\n", MUL(2, 3));
    // printf("%d\n", MUL(2 + 1, 3 + 2));
    // printf("%d\n", (2 + 1) * (3 + 2));
    return 0;
}