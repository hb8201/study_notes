#include <stdio.h>

int main()
{
    int a[10] = {0};
    int b, n;

    while (1)
    {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n <= 0)
            break;

        while (n > 0)
        {
            b = n % 10;
            if (a[b] == 1)
                break;
            a[b] = 1;
            n /= 10;
        }

        if (n > 0)
            printf("Reoeated digit\n");
        else
            printf(" No reoeated digit\n");
    }

    return 0;
}