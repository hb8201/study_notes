#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next[] = {-1, 0, 1, 2,};

int dizhi(char *a, char *b);
void quanbu(int a, int b);

int main()
{
    char *a = "aabcaaabcabc";
    char *b = "aaab";
    int c = dizhi(a, b);
    quanbu(c, strlen(b));

    return 0;
}

int dizhi(char *a, char *b)
{
    int i = 0, j = 0, len;
    for (; i < strlen(a);)
    {
        len = 0;
        j = next[j];
        if (j == -1)
            j = 0;
        for (; j < strlen(b);)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
                len++;
                if (len == strlen(b))
                    return i - 1;
            }
            else
            {
                i++;
                break;
            }
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