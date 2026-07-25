#include <stdio.h>

int main()
{
    int m, n, t;

    printf("Enter two integers:");
    scanf("%d %d", &m, &n);

    if (n > m)
    {
        t = n;
        n = m;
        m = t;
    }

    while (n)
    {
        int a;
        a = m;
        m = n;
        n = a % n;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}