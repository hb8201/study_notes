#include <stdio.h>

int main()
{
    int n;

    printf("输入大于零的数：");
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i * i);
        }
    }

    return 0;
}