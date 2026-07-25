// 最大公约数 递归
#include <stdio.h>

int lab(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return lab(y, x % y);
}

int main()
{
    int a, b, t;
    printf("求两个正数的最大公约数(a,b)：");
    scanf("%d,%d", &a, &b);

    if (b > a)
    {
        t = a;
        a = b;
        b = t;
    }

    t = lab(a, b);
    printf("%d与%d的最大公约数是%d\n", a, b, t);

    return 0;
}