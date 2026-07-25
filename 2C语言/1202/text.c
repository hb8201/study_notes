#include <stdio.h>

int main()
{
    int a, b, c;
    printf("请输入三个整数：");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        if (b > c)
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", a, b, c);
        else if (a > c)
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", a, c, b);
        else
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", c, a, b);
    }
    else
    {
        if (a > c)
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", b, a, c);
        else if(b > c)
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", b, c, a);
        else
            printf("最大值：%d\n中间值：%d\n最小值：%d\n", c, b, a);
            
    }
    return 0;
}