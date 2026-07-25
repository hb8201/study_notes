#include <stdio.h>
#include "my.h"

int main()
{
    float m, n;
    printf("请输入需要纳税的金额：");
    scanf("%f", &m);

    n = pay_taxes(m);
    printf("税金：%.2f\n", n);
    return 0;
}