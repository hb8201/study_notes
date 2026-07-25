#include <stdio.h>

int fun2(int n)
{
    if ((n == 1 ) || (n == 2))
        return 1;
    return fun2(n - 1) + fun2(n - 2);
}

int main()
{
    int n = 45;
    printf("%d\n", fun2(n));

    return 0;
}