// 斐波那契数列 循环
#include <stdio.h>

int main()
{
    int n;
    printf("用循环求斐波那契数列，数列长度为（大于2）：");
    scanf("%d", &n);
    int a[n];
    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    printf("前%d项为：\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}