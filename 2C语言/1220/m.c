// m.c
// 二维数组
#include <stdio.h>

int main()
{
    int m[9][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        m[i][0] = 1;
        m[i][i] = 1;
        for (int j = 0; j < 9; j++)
        {
            if (i >= 2 && j < i)
            {
                m[i][j] = m[i-1][j] + m[i-1][j-1];
            }
            if (m[i][j] != 0)
                printf("%2d ", m[i][j]);
        }
        printf("\n");
    }

    // int m[3][4] = {0};
    // // 3行4列矩阵
    // // i, j, k
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("[%d][%d]=%d\t", i, j, m[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}