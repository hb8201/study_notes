// 1026.c
#include <stdio.h>

int main()
{
    // 输入年月，输出有多少天
    // int y, m, d;
    int y;
    int m;
    int d;

    printf("输入年月（2025/12）：");
    scanf("%d/%d", &y, &m);

    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        d = 31;
        break;
    case 2:
        d = 28;
        // 判断闰年
        // 1. 被 400 整除
        // 2. 被 4 整除且不被 100 整除
        if (y % 400 == 0 
                || (y % 4 == 0 && y % 100 != 0))
        {
            d = 29;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        d = 30;
        break;
    default:
        d = -1;
        break;
    }

    // 结果
    if (d == -1)
    {
        printf("月份出错，请重新输入\n");
    }
    else
    {
        printf("%d/%d有%d天\n", y, m, d);
    }

    return 0;
}