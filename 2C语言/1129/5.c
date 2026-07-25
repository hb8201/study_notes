#include <stdio.h>

int main()
{
    int i, j, x = 0, y = 0;
    int a[16], b[4], c[4];
    printf("Enter the number from 1 to 16 in any order:\n");
    for (i = 0; i < 16; i++)
    {
        scanf("%d", &a[i]);
        if (i % 4 == 0)
            printf("%2d", a[i]);
        else if ((i + 1) % 4 == 0)
            printf("%4d\n", a[i]);
        else
            printf("%4d", a[i]);
        if(i % 5 == 0)
            x += a[i];
    }
    printf("\n");
    for (j = 0; j < 4; j++)
    {
        b[j] = a[4 * j] + a[4 * j + 1] + a[4 * j + 2] + a[4 * j + 3];
        c[j] = a[j] + a[j + 4] + a[j + 8] + a[j + 12];
    }
    y = a[3] + a[6] + a[9] + a[12];
    printf("Row sums:%3d%3d%3d%3d\n", b[0], b[1], b[2], b[3]);
    printf("Column sums:%3d%3d%3d%3d\n", c[0], c[1], c[2], c[3]);
    printf("Diagonal sums:%3d%3d\n", x, y);
    return 0;
}