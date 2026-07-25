#include <stdio.h>

int main()
{
    int i = 1;
    float q, e = 1;

    printf("当前项小于多少时，输出e的值: ");
    scanf("%f", &q);

    while (1)
    {
        int a = 1;

        for (int j = 1; j <= i; j++)
            a *= j;

        e = e + 1.0 / a;

        if (1.0 / a < q)
            break;
        i++;
    }

    printf("%f\n", e);

    return 0;
}