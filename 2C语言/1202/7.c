#include <stdio.h>

int main()
{
    int a, b, c, d, t;
    printf("Enter four integers:");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }

    if (c < d)
    {
        t = c;
        c = d;
        d = t;
    }

    if (a > c)
        printf("Largest: %d\n", a);
    else
        printf("Largest: %d\n", c);

    if (b > d)
        printf("Smallest: %d\n", d);
    else
        printf("Smallest: %d\n", b);

    return 0;
}