#include <stdio.h>

int main()
{
    int a[10] = {0};
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        int b = n % 10;
        a[b] += 1;
        n /= 10;
    }

    printf("Digit:\t\t0  1  2  3  4  5  6  7  8  9\n");
    printf("Occurrences:\t");

    for (int i = 0; i < 10; i++)
        printf("%d  ", a[i]);

    printf("\n");

    return 0;
}