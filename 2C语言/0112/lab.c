#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fun()
{
    int a;            // a 最小为123   c 最大为987，所以 a 最大为329

    for (int a = 123; a <= 329; a++)
    {
        int w[10] = {0};
        int a1, b1, c1;
        a1 = a;
        b1 = 2 * a;
        c1 = 3 * a;

        while (a1)
        {
            w[a1 % 10]++;
            a1 /= 10;
        }
        while (b1)
        {
            w[b1 % 10]++;
            b1 /= 10;
        }
        while (c1)
        {
            w[c1 % 10]++;
            c1 /= 10;
        }

        int x = 0;   // 计数
        if (w[0] == 0)
        {
            for (int i = 1; i < 10; i++)
            {
                if (w[i] == 1)
                    x++;
            }
        }

        if (x == 9)
            printf("%d,%d,%d\n", a, 2 * a, 3 * a);
    }
}

int main()
{
    fun();
    return 0;
}