#include <stdio.h>
#include "my.h"

int main()
{
    int a, b, c;
    printf("求x的n次方（x,n）：");
    scanf("%d,%d", &a, &b);

    c = power(a, b);
    
    printf("结果为：%d\n", c);
    return 0;
}