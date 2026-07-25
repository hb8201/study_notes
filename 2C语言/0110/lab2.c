#include <stdio.h>
#include <string.h>

void dx(char x[])
{
    int i = 0, j = 0;
    char *b[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    char *c[] = {"元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};
    printf("大写：");

    while (1)
    {
        if (x[j] == '\n')
            break;
        j++;
    }

    while (1)
    {
        if (x[i] == '\n')
            break;

        if ((b[x[i - 1] - '0'] == "零" && b[x[i] - '0'] == "零")){}
        else
            printf("%s", b[x[i] - '0']);

        if (b[x[i] - '0'] != "零" || c[j - 1] == "万" || j == 1)
            printf("%s", c[j - 1]);

        i++;
        j--;
    }
    printf("\n");
}

int main()
{
    char a[99];
    printf("输入金额：");
    fgets(a, 99, stdin);
    dx(a);

    return 0;
}