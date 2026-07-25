// 斐波那契数列 递归
#include <stdio.h>

int lab(int a[], int x)
{
    if (x <= 2)
        return a[x] = 1;
    lab(a, x - 1);
    return a[x] = a[x - 1] + a[x - 2];
}

int main()
{
    int n;
    printf("用递归求斐波那契数列，数列长度为（大于2）：");
    scanf("%d", &n);

    int a[n];
    a[0] = 0;
    a[1] = 1;
    lab(a, n - 1);

    printf("前%d项为：\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}