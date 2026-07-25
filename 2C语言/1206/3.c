#include <stdio.h>

int main()
{
    int a, b, a1, b1;

    printf("Enter a fraction:");
    scanf("%d/%d", &a, &b);

    a1 = a;
    b1 = b;

    if (a > b)
    {
        while (b1)
        {
            int t;
            t = a1;
            a1 = b;
            b1 = t % b1;
        }
        printf("In lowest terms: %d/%d\n",a / a1, b / a1 );
    }
    else
    {
        while (a1)
        {
            int t;
            t = b1;
            b1 = a;
            a1 = t % a1;
        }
        printf("In lowest terms: %d/%d\n",a / b1, b / b1 );
    }

    return 0;
}