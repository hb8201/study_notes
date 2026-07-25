#include <stdio.h>

int main()
{
    int a;         // a 用户股票数量
    float b, c, d; // b 用户每股价格，c 用户佣金， d 对手佣金
    printf("输入股票数量和每股价格：");
    scanf("%d %f", &a, &b);

    if ((a * b) < 2500.00f)
        c = 30 + a * b * 0.017f;
    else if ((a * b) < 6250.00f)
        c = 56 + a * b * 0.0066f;
    else if ((a * b) < 20000.00f)
        c = 56 + a * b * 0.0034f;
    else if ((a * b) < 50000.00f)
        c = 56 + a * b * 0.0022f;
    else if ((a * b) < 500000.00f)
        c = 56 + a * b * 0.0011f;
    else
        c = 56 + a * b * 0.0009f;

    if (c < 39)
        c = 39;

    if (a < 2000)
        d = 33 + a * 0.3;
    else
        d = 33 + a * 0.2;

    printf("经纪人佣金：%.2f\n", c);
    printf("竞争对手佣金：%.2f\n", d);

    return 0;
}