#include <stdio.h>

#define n 10

int main()
{
    int a[n];
    int b;

    printf("输入一串数(** ** **)：");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("反向输出：");

    for (int i = n - 1; i >= 0; i--)
        printf("%d  ", a[i]);

    printf("\n");

    b = sizeof(a) / sizeof(a[0]);

    printf("长度：%d\n", b);

    return 0;
}