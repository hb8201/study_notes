#include <stdio.h>
#include <string.h>

void Hex(int x)
{
    printf("16进制为：");
    char a[] = "0123456789ABCDEF";
    int i = 0, y = x;

    while (y)
    {
        y /= 16;
        i++;
    }

    char b[i];
    b[i] = '\0';
    for (int j = i - 1; j >= 0; j--)
    {
        b[j] = a[x % 16];
        x /= 16;
    }

    printf("0x%s\n", b);
}

int main()
{
    int a;
    printf("请输入整数：");
    scanf("%d", &a);
    Hex(a);
    return 0;
}