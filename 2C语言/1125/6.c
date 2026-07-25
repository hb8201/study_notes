#include <stdio.h>
int main()
{
    float x, y;
    printf("输入x的值：");
    scanf("%f", &x);
    y = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("%f\n", y);
    return 0;
}