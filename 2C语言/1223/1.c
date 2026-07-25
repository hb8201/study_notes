#include <stdio.h>
#include "my.h"

int main()
{
    int n;
    printf("输入一串整数，数量为：");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    selection_sort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}