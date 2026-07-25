// work1.c
#include <stdio.h>

// n!
int fact(int n)
{
    // O(n)
    int r = 1;
    for (int i = 1; i <= n; i++)
    {
        r *= n;
    }
    return r;
}

// f5
// 5 * f4
// 5 * 4 * f3
// 5 * 4 * 3 * f2
// 5 * 4 * 3 * 2 * f1

int c = 0;
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int fact1(int n)
{
    c++;
    if (n == 1)
        return 1;
    return n * fact1(n - 1);
}

int main()
{
    int a = fact1(10);
    printf("%d,%d\n", a, c);
    // int n = 10000;
    // int sum = 0;
    // O(n)
    // for (int i = 0; i < n; i++)
    // {
    //     sum += i;
    // }
    // O(1)
    // sum = n * (n + 1) / 2;
    return 0;
}