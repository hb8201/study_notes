// 荷兰国旗问题(数组、双链表)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data[12];
    int len;
} List;

int main()
{
    List l = {{1, 0, 2, 1,0, 0, 1, 2, 2, 1, 0, 2}, 12};
    int i = -1, j = 0, k = l.len, t;

    while (j < k)
    {
        switch (l.data[j])
        {
            case 0:
            {
                i++;
                t = l.data[i];
                l.data[i] = l.data[j];
                l.data[j] = t;
                j++;
                break;
            }
            case 1: j++;
                break;
            case 2:
            {
                k--;
                t = l.data[k];
                l.data[k] = l.data[j];
                l.data[j] = t;
            }
        }
    }
    printf("{");
    for (int w = 0 ; w < l.len; w++)
        printf("%d,", l.data[w]);
    printf("\b}\n");

    return 0;
}

