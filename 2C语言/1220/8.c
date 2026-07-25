#include <stdio.h>

int main()
{
    int a[5][5];
    int b[5] = {0};                             //学生总分
    float c[5] = {0};                           //学生平均分
    float d[5] = {0};                           //科目平均分
    int max[5] = {0};                           //科目最高分
    int min[5] = {100,100,100,100,100};         //科目最低分

    for (int i = 0; i < 5; i++)
    {
        printf("学生%d: ", i + 1);
        for (int j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            b[i] += a[i][j];
            d[i] += a[j][i];
        }
        c[i] = b[i] / 5.0;
        d[i] = d[i] / 5.0;
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (a[i][j] >= max[j])
                max[j] = a[i][j];
            if (a[i][j] <= min[j])
                min[j] = a[i][j];
        }
    }

    printf("\n");

    printf("学生总分：\t");
    for (int i = 0; i < 5; i++)
        printf("%2d ", b[i]);

    printf("\n学生平均分：\t");
    for (int i = 0; i < 5; i++)
        printf("%.2f ", c[i]);

    printf("\n科目平均分：\t");
    for (int i = 0; i < 5; i++)
        printf("%.2f ", d[i]);

    printf("\n科目最高分：\t");
    for (int i = 0; i < 5; i++)
        printf("%2d ", max[i]);
    
    printf("\n科目最低分：\t");
    for (int i = 0; i < 5; i++)
        printf("%2d ", min[i]);

    printf("\n");

    return 0;
}