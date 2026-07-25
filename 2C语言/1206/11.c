#include <stdio.h>

int main()
{
    int n;
    float e = 1.0;

    printf("求e=1+1/1!+1/2!+1/3!+...+1/n!,请输入n的值: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a = 1;

        for (int j = 1; j <= i; j++)
            a *= j;

        e = e + 1.0 / a;
    }

    printf("e = %f\n", e);

    return 0;
}