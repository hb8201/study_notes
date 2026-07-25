#include <stdio.h>

int main()
{
    int a, b;

    printf("输入大于零的数字：");
    scanf("%d", &a);
    printf("逆序是：");
    
    do
    {
        b = a % 10;
        printf("%d", b);
        a = a / 10;
        if(a == 0)
            printf("\n");
    } while (a);
    

    return 0;
}