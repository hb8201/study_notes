#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dizhi(char *a, char *b);
void quanbu(int a, int b);

int main()
{
    char *a = "ababababc";
    char *b = "abc";
    int c = dizhi(a, b);
    quanbu(c, strlen(b));

    return 0;
}

int dizhi(char *a, char *b)
{
    int i, j, k, v;
    for (i = 0; i < strlen(a); i++)
    {
        v = 0;
        k = i;
        for (j = 0; j < strlen(b); j++)
        {
            if (a[k] == b[j])
            {
                v++;
                if (v == strlen(b))
                    return k;
                k++;
            }
            else
                break;
        }
    }
    return -1;
}
void quanbu(int a, int b)
{
    if (a == -1)
        printf("没找到");
    else
    for (int i = b; i > 0; i--)
        printf("%d ", a - i + 1);
    printf("\n");
}

