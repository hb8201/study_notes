#include <stdio.h>

int main()
{
    double a, b;
    printf("输入需要纳税的收入：");
    scanf("%lf", &a);
    if (a < 750)
        b = a * 0.01;
    else if (a < 2250)
        b = 7.50 + (a - 750) * 0.02;
    else if (a < 3750)
        b = 37.50 + (a - 2250) * 0.03;
    else if (a < 5250)
        b = 82.50 + (a - 3750) * 0.04;
    else if (a < 7000)
        b = 142.50 + (a - 5250) * 0.05;
    else
        b = 230.00 + (a - 7000) * 0.06;
    printf("%.2lf\n", b);
    return 0;
}