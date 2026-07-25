#include <stdio.h>
#include "my.h"

int main()
{
    float a, b;
    printf("输入x的值：");
    scanf("%f", &a);
    b = polynomial(a);
    printf("y的值是：%.2f\n", b);
    return 0;
}