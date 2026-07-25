#include <stdio.h>

int main()
{
    char ch[100];
    char c;
    int i, j, z;

    printf("Enter a sentence: ");
    for (i = 0; i < 100; i++)
    {
        scanf("%c", &ch[i]);
        if (ch[i] == '.' || ch[i] == '?' || ch[i] == '!')
        {
            c = ch[i];
            z = i;
            break;
        }
    }

    printf("Reversal of sentence: ");
    for (j = i - 1; j >= 0; j --)
    {
        if (ch[j] == ' ')
        {
            for (int k =j + 1; k < z; k++)
            {
                printf("%c", ch[k]);
            }
            z = j;
            printf(" ");
        }
    }

    for (int l = 0; l < 100; l++)
    {
        if (ch[l] == ' ')
            break;
        printf("%c", ch[l]);
    }

    printf("%c\n", c);

    return 0;
}