#include <stdio.h>

int main()
{
    int a, b, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
        first_sum, second_sum, total;

    printf("Enter the first (single) digit:");
    scanf("%1d", &a);
    printf("Enter first group of five digits:");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter second group of five digits:");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    first_sum = a + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    total = 9 - ((total - 1) % 10);

    printf("请输入最后一位：");
    scanf("%1d", &b);
    if(total == b)
        printf("VALID\n");
    else
        printf("NOT VALID\n");

    return 0;
}