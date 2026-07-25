// bit.c
// 位运算
#include <stdio.h>

int main()
{
    // int n;
    // printf("请输入横数：");
    // scanf("%d", &n);

    // // 与

    // if (n & 1 == 1)
    // {
    //     printf("奇数 - odd\n");
    // }
    // else
    // {
    //     printf("偶数 - even\n");
    // }

    // int a = 2;
    // int b = 3;

    // // 1. 使用临时变量       t
    // // 2. 不使用临时变量      a = a + b, b = a - b, a = a - b;
    // // 3. 异或              a = a ^ b, b = a ^ b, a = a ^ b
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
    // printf("%d, %d\n", a, b);


    // // 异或
    // // 找出出现一次的数
    // int a[] = {12, 13, 42, 13, 15, 12, 15};
    // int n = 0;
    // for (int i = 0; i < 7; i++)
    // {
    //     n = n ^ a[i];
    // }
    // printf("%d\n", n);





    // 负数，按位取反加一
    // int a = 3;      // 0000 0000 0000 0000 0000 0000 0000 0011
    // int b = ~a;     // 1111 1111 1111 1111 1111 1111 1111 1100      -4

    // printf("%d\n", b);

    // printf("%032b\n", a);
    // printf("%b\n", b);

    // printf("%d,%d\n", 12, ~12);         // 12,-13
    // printf("%d,%d\n", -12, ~(-12));     // -12,11
    // printf("%d,%d\n", 0, ~0);           // 0,-1

    // printf("%d\n", !a);                 // 非 0
    // printf("%d\n", !(-3));              // 非 0

    int n;
    printf("请输入横数：");
    scanf("%d", &n);

    // // 方向反了
    // while (n > 0)
    // {
    //     printf("%d", n % 2);
    //     n /= 2;
    // }

    for (int i = 0; i < 32; i++)
    {
        // 0000 0000 0000 0000 0000 0000 0000 0011
        // 01
        //printf("%d", (n >> (31 - i)) & 1);                        // 方案一
        //printf("%d", (n & (1 << (31 - i))) == (1 << (31 - i)));   // 方案二
        if (i % 8 == 7)
        printf(" ");
    }
    
    
    return 0;
}