#include <stdio.h>
int main()
{
    float x, y;
    printf("输入x的值：");
    scanf("%f", &x);
    y = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    printf("%f\n", y);
    return 0;
}