#include <stdio.h>
int main()
{
    float r, v;
    printf("请输入球体半径：");
    scanf("%f", &r);
    v = 4.0f / 3.0f * 3.14159265 * r * r * r;
    printf("体积为：%f\n", v);
    return 0;
}