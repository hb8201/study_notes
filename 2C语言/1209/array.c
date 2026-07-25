// array.c
// 数组
#include <stdio.h>

#define N 6

int main()
{
    // 成绩等级
    // 90           A
    // 80 ~ 90      B
    // 70 ~ 80      C
    // 60 ~ 70      D
    // 60           E
    int n[4] = {60 ,70, 80, 90};
    char level[5] = {'E', 'D', 'C', 'B', 'A'};

    int s;
    printf("请输入成绩：");
    scanf("%d", &s);

    int i;
    for (i = 0; i < 4; i++)
    {
        if (s < n[i])
            break;
    }
    printf("成绩：%d，等级：%c\n", s, level[i]);

    // // 输入取款金额，输出各个面值多少张（总张数最少）
    // // 879
    // // 100  8
    // // 50   1
    // // 20   1
    // // 10   0
    // // 5    1
    // // 1    4
    // int m;
    // printf("请输入取款金额：");
    // scanf("%d", &m);

    // // 各种面值
    // int rmb[6] = {100, 50, 20, 10, 5, 1};
    // // 各种面值张数
    // int n[6] = {0};

    // for (int i = 0; i < 6; i++)
    // {
    //     n[i] = m / rmb[i];
    //     m = m % rmb[i];
    //     //
    //     if (n[i] != 0)
    //         printf("面值：%3d  %3d张\n", rmb[i], n[i]);
    // }

    // int m;
    // printf("月份：");
    // scanf("%d", &m);

    // // 下标
    // int days[] = {31, 28, 31, 30,
    //               31, 30, 31, 31,
    //               30, 31, 30, 31};

    // if (m >= 1 && m <= 12)
    // {
    //     printf("%d月%d天\n", m, days[m - 1]);
    // }

    // int n;
    // n = 3;

    // // 数组 a 容量不可变
    // int a[n];

    // int a[3] = {1, 2, 3};
    // a = {4, 5, 6};            不可行

    // 声明数组变量
    // int a[9] = {0};
    // a[8] = 999;
    // //a[9] = 1000;    // 不可以 （C缺陷与陷阱）

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("a[%d]=%d\n", i, a[i]);
    // }

    return 0;
}