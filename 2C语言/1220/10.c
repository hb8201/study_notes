#include <stdio.h>

int main()
{
    int a[8] = {480, 543, 679, 767, 840, 945, 1140, 1305};
    int b[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int h1, m1, x, y, z;

    printf("输入时间（24小时制 **:**）：");
    scanf("%d:%d", &h1, &m1);
    x = h1 * 60 + m1;

    if (x <= a[0] || x >= a[7])
    {
        y = a[0];
        z = b[0];
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            if (x > a[i] && x < a[i + 1])
            {
                if (x <= (a[i] + a[i + 1]) / 2)
                {
                    y = a[i];
                    z = b[i];
                }
                else
                {
                    y = a[i + 1];
                    z = b[i + 1];
                }
            }
        }
    }

    printf("最近的起飞时间：%2d:%02d，到达时间：%2d:%02d\n", y / 60, y % 60, z / 60, z % 60);

    return 0;
}