#include <stdio.h>

int main()
{
    int d, w;

    printf("Enter number of days in month: ");
    scanf("%d", &d);
    printf("Enter starting day of the week（1=Sun，7=Sat）: ");
    scanf("%d", &w);
    printf("一  二  三  四  五  六  日\n");

    for (int i = 1; i < w; i++)
        printf("    ");
    for (int j = 1; j <= d; j++)
    {
        printf("%2d  ", j);
        if ((j + w - 1) % 7 == 0)
            printf("\n");
        if ( j == d)
            printf("\n");
    }

    return 0;
}