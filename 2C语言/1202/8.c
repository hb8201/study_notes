#include <stdio.h>

#define t1 ( 8 * 60 + 51.5) // 第一次和第二次起飞时间的中间值（用分表示）
#define t2 (10 * 60 + 31.0)
#define t3 (12 * 60 +  3.0)
#define t4 (13 * 60 + 23.5)
#define t5 (14 * 60 + 52.5)
#define t6 (17 * 60 + 22.5)
#define t7 (20 * 60 + 22.5)

int main()
{
    int a, b;   // 输入的时间
    int c;      // 输入时间化为分钟

    printf("输入时间（24小时制）：");
    scanf("%d:%d", &a, &b);
    c = a * 60 + b;

    if (c < t1)
        printf("起飞时间：8:00am，到达时间：10:16am\n");
    else if (c < t2)
        printf("起飞时间：9:43am，到达时间：11:52am\n");
    else if (c < t3)
        printf("起飞时间：11:19am，到达时间：1:31pm\n");
    else if (c < t4)
        printf("起飞时间：12:47pm，到达时间：3:00pm\n");
    else if (c < t5)
        printf("起飞时间：2:00pm，到达时间：4:04pm\n");
    else if (c < t6)
        printf("起飞时间：3:45pm，到达时间：5:55pm\n");
    else if (c < t7)
        printf("起飞时间：7:00pm，到达时间：9:20pam\n");
    else
        printf("起飞时间：9:45pm，到达时间：11:58pm\n");

    return 0;
}