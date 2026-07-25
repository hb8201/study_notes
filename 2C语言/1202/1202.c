// 1202.c
// 关系运算和逻辑运算
// 函数名，参数列表，函数体，返回值类型
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("请输入三个整数：");
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int max;
    if (x > y)
    {
        // x, z
        if ( x > z)
            max = x;
        else
            max = z;
    }
    else
    {
        // y, z
        max = y > z 
                ? y 
                : z;
    }
    printf("最大值是%d\n", max);

    // int z = n % 2;
    // if (0 == z)
    // {
    //     // shift + alt + 下
    //     printf("%d是偶数\n", n);
    // }
    // else
    // {
    //     printf("%d是奇数\n", n);
    // }

    // a ? b : c    a成立为b，不成立为c
    //%d, %f %c %s %p
    // printf("%d 是 %s 数\n", n, n % 2 == 0 ? "偶" : "奇");
    printf("over\n");

    //  -------------------------------------------
    // int a = 1;
    // int b = 2;
    // printf("%d\n", a == b);
    // printf("%d\n", a != b);
    // printf("%d\n", a > b);
    // printf("%d\n", a >= b);
    // printf("%d\n", a < b);
    // printf("%d\n", a <= b);

    // // _Bool
    // // _Bool b1 = a > b;
    // // bool b2 = a > b;
    // // bool b3 = true;
    // // bool b4 = false;

    return 0;
}