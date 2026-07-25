#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX 9
#define MAX 10

int main()
{
    // int a[MAX] = {9, 32, 7, 21, 13, 42, 5, 1, 81};
    int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int b = (MAX - 2) / 2;      // 完全二叉树最后一个度2节点在数组中的下标
    int t, m = 0;

    while (m != b)
    {
        for (int i = b; i >= m; i--)
        {
            if ((i * 2 + 2) > MAX)
            {
                if (a[i] > a[i * 2 + 1])
                    continue;
                t = a[i];
                a[i] = a[i * 2 + 1];
                a[i * 2 + 1] = t;
            }
            else if (a[i * 2 + 1] > a[i * 2 + 2])
            {
                if (a[i] > a[i * 2 + 1])
                    continue;
                t = a[i];
                a[i] = a[i * 2 + 1];
                a[i * 2 + 1] = t;
            }
            else
            {
                if (a[i] > a[i * 2 + 2])
                    continue;
                t = a[i];
                a[i] = a[i * 2 + 2];
                a[i * 2 + 2] = t;
            }
        }
        m++;
    }

    printf("{");
    for (int i = 0; i < MAX; i++)
        printf("%d,", a[i]);
    printf("\b}\n");

    return 0;
}








