#include <stdio.h>

int main()
{
    int i = 0;
    float x, y, z;
    printf("Enter amount of loan:");
    scanf("%f", &x);
    printf("Enter interset rate:");
    scanf("%f", &y);
    printf("Enter monthly payment:");
    scanf("%f", &z);

    while (1)
    {
        x = x - z + (x * y) / 1200;
        i ++;
        printf("第 %d 次还贷后剩余的贷款金额: $%.2f\n", i, x);

        if (x <= 0)
            break;
    }
    
    return 0;
}