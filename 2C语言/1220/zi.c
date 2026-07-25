// zi.c
#include <stdio.h>

int main()
{
    // char zi[];      // 字符数组
    // char *zi;       // 字符指针
    int a, i = 0;             // a 的取值范围 -2147483648~2147483647
    char *zi1[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    char *zi2[] = {"拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾"};
    int zi3[10] = {0};

    printf("输入金额：");
    scanf("%d", &a);


    while (a > 0)
    {
        zi3[i] = a % 10;
        a /= 10;
        i++;
    }
        
    for (int j = i - 1; j >= 0; j--)
    {
        if (zi1[zi3[j]] != "零")
        {
            printf("%s", zi1[zi3[j]]);
            if (j - 1 >= 0)
            printf("%s", zi2[j - 1]);
        }
    }

printf("\n");

    return 0;
}