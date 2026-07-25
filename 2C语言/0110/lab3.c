#include <stdio.h>
#include <string.h>

int digit(char a[])         // 判断a是几位数
{
    int i = 0;
    while (1)
    {
        if (a[i] == '\n')
            break;
        i++;
    }
    return i;
}

void add(char a[], char b[])
{
    int a1 = digit(a);
    int b1 = digit(b);
    int c1;             // c1 表示几位数

    if (a1 > b1)
        c1 = a1 + 1;
    else
        c1 = b1 + 1;
    
    char c[c1 + 1];
    c[c1] = '\0';
    int w1 = 0, w2 = 0;           // w1表示上一位进位，w2表示下一位进位

    while (1)
    {
        int x = 0;                           // 表示当前位的和值
        if (a1 - 1 >= 0 && b1 - 1 >= 0)
        {
            x = a[a1 - 1] + b[b1 - 1] + w1 - '0' - '0';
            if (x < 10)
            {
                c[c1 - 1] = x + '0';
                w2 = 0;
            }
            else
            {
                w2 = 1;
                x -= 10;
                c[c1 - 1] = x + '0';
            }
            w1 = w2;
            w2 = 0;
            c1--;
            a1--;
            b1--;
        }
        else
        {
            if (a1 - 1 < 0 && b1 - 1 >= 0)
            {
                c[c1 - 1] = b[b1 - 1] + w1;
                w1 = 0;
                b1--;
                c1--;
            }
            else if (b1 - 1 < 0 && a1 - 1 >= 0)
            {
                c[c1 - 1] = a[a1 - 1] + w1;
                w1 = 0;
                a1--;
                c1--;
            }
            else if (b1 - 1 < 0 && a1 - 1 < 0)
            {
                c[c1 - 1] = w1 + '0';
                printf("%s\n", c);
                break;
            }
        }
    }
}

void sub(char a[], char b[])
{
    int a1 = digit(a);
    int b1 = digit(b);
    int c1, f;          // f 判断符号

    if (a1 > b1)
    {
        f = 1;      // 正
        c1 = a1 + 1;
    }
    else if (a1 < b1)
    {
        f = 0;      // 负
        c1 = b1 + 1;
    }
    else
    {
        c1 = a1 + 1;
        if (a[0] > b[0])
            f = 1;
        else
            f = 0;
    }

    char c[c1 + 1];
    c[c1] = '\0';
    int w1 = 0, w2 = 0;             // w1表示上一位借位，w2表示下一位借位

    while (1)
    {
        int x = 0;                  // 表示当前位的差值
        if (a1 - 1 >= 0 && b1 - 1 >= 0)
        {
            if (f)
                x = a[a1 - 1] - b[b1 - 1] - w1;
            else
                x = b[b1 - 1] - a[a1 - 1] - w1;

            if (x >= 0)
            {
                c[c1 - 1] = x + '0';
                w2 = 0;
            }
            else
            {
                w2 = 1;
                x += 10;
                c[c1 - 1] = x + '0';
            }
            w1 = w2;
            w2 = 0;
            c1--;
            a1--;
            b1--;
        }
        else
        {
            if (a1 - 1 < 0 && b1 - 1 >= 0)
            {
                c[c1 - 1] = b[b1 - 1] - w1;
                w1 = 0;
                b1--;
                c1--;
            }
            else if (b1 - 1 < 0 && a1 - 1 >= 0)
            {
                c[c1 - 1] = a[a1 - 1] - w1;
                w1 = 0;
                a1--;
                c1--;
            }
            else if (b1 - 1 < 0 && a1 - 1 < 0)
            {
                if (f)
                    c[0] = '+';
                else
                    c[0] = '-';
                printf("%s\n", c);
                break;
            }
        }
    }
}

int main()
{
    char a[99];
    char b[99];

    printf("请输入第一个数：");
    fgets(a, 99, stdin);
    printf("请输入第二个数：");
    fgets(b, 99, stdin);
    add(a, b);
    sub(a,b);
    
    return 0;
}