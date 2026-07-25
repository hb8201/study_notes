#include <stdio.h>

int main()
{
    int a[5][5];
    int r[5] = {0}, c[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            r[i] += a[i][j];
            c[i] += a[j][i];
        }
    }

    printf("Row totals: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", r[i]);
    printf("\n");

    printf("Column totals: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}