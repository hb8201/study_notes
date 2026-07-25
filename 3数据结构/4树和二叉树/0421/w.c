#include <stdio.h>
#include <stdlib.h>
#define A 5
#define B 7
#define KEY 7

int main()
{
    int a[A] = {36, 15, 40, 63, 22};
    int b[B] = {0};
    int ha;
    for (int i = 0; i < A; i++)
    {
        ha = a[i] % KEY;
        while (b[ha] != 0)
        {
            ha++;
            if (ha == B)
                ha = 0;
        }
        b[ha] = a[i];
    }
    for (int i = 0; i < B; i++)
    {
        printf("%d:%d\n", i, b[i]);
    }

    return 0;
}
