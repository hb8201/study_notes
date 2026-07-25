#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define F 4

int main()
{
    int f, n = 26;
    int a1 = 0, a2 = 0;
    int z[4] = {0};
    char ch[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            ch[i][j] = '.';
    }

    ch[a1][a2] = 'A';
    srand((unsigned)time(NULL)); // 用当前时间戳设置种子

    while (n > 1)
    {
        f = rand() % F; // a + rand() % (b - a + 1) 生成随机数 a~b

        if (z[0] == 1 && z[1] == 1 && z[2] == 1 && z[3] == 1)
            break;
        
        switch (f)
        {
        case 0: // 上
        {
            if (a1 - 1 >= 0 && ch[a1 - 1][a2] == '.')
            {
                ch[a1 - 1][a2] = ch[a1][a2] + 1;
                a1--;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[0] = 1;
            break;
        }
        case 1: // 右
        {
            if (a2 + 1 <= 9 && ch[a1][a2 + 1] == '.')
            {
                ch[a1][a2 + 1] = ch[a1][a2] + 1;
                a2++;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[1] = 1;
            break;
        }
        case 2: // 下
        {
            if (a1 + 1 <= 9 && ch[a1 + 1][a2] == '.')
            {
                ch[a1 + 1][a2] = ch[a1][a2] + 1;
                a1++;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[2] = 1;
            break;
        }
        case 3: // 左
        {
            if (a2 - 1 >= 0 && ch[a1][a2 - 1] == '.')
            {
                ch[a1][a2 - 1] = ch[a1][a2] + 1;
                a2--;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[3] = 1;
            break;
        }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", ch[i][j]);
        printf("\n");
    }
}