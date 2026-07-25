#include <stdio.h>

int fun1(int n)
{
    int i = 2;
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for (; i < n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[i - 1];
}

int main()
{
    int n = 60;
    printf("%d", fun1(n));

    return 0;
}