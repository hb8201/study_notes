# include <stdio.h>

int main()
{
    int n, x, y, z;
    printf("生成一个指定大小的幻方。\n");
    printf("幻方的大小必须是1到99的奇数。\n");
    printf("请输入幻方的阶数：");
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }

    x = 0;
    y = n / 2;
    z = n * n;
    a[x][y] = 1;

    while (z > 0)
    {
        if (x - 1 < 0)
        {
            int x1, y1;         //下一步位置
            x1 = n - 1;

            if (y + 1 >= n)
                y1 = 0;
            else
                y1 = y + 1;

            if (a[x1][y1] != 0)
            {
                a[x + 1][y] = a[x][y] + 1;
                x++;
                z--;
            }
            else
            {
                a[x1][y1] = a[x][y] + 1;
                x = x1;
                y = y1;
                z--;
            }

        }
        else
        {
            int x1, y1;
            x1 = x - 1;

            if (y + 1 >= n)
                y1 = 0;
            else
                y1 = y + 1;

            if (a[x1][y1] != 0)
            {
                a[x + 1][y] = a[x][y] + 1;
                x++;
                z--;
            }
            else
            {
                a[x1][y1] = a[x][y] + 1;
                x = x1;
                y = y1;
                z--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d  ", a[i][j]);
        printf("\n");
    }

    return 0;
}