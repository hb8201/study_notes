#include <stdio.h>
#define NUM_RATES ((int)(sizeof(a) / sizeof(a[0])))
#define D 100
int main()
{
    int i, l, n, y;
    double a[5];
    printf("Enter interest rate: ");
    scanf("%d", &l);
    printf("Enter number of years: ");
    scanf("%d", &n);
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", l + i);
        a[i] = D;
    }
    printf("\n");
    for (y = 1; y <= n; y++)
    {
        printf("%3d    ", y);
        for (i = 0; i < NUM_RATES; i++)
        {
            for (i = 1; i < 13; i++)
                a[i] += (l + i) / 100.0 / 12 * a[i];
            printf("%7.2f", a[i]);
        }
        printf("\n");
    }
    return 0;
}