#include <stdio.h>
#include "my.h"

int main()
{
    int n;
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

    create_magic_square(n, a);
    print_magic_square(n, a);

    return 0;
}