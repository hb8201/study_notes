#include <stdio.h>

int main()
{
    int a[10] = {0};
    int n, c = 0;

    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Repeated digit(s): ");
    while (n > 0)
    {
        int b = n % 10;
        if (a[b] == 1)
        {
            printf("%2d", b);
            c = 1;
        }
        a[b] = 1;
        n /= 10;
    }

    if (c == 0)
        printf("没有");

    printf("\n");

    return 0;
}