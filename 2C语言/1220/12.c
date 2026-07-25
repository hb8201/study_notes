#include <stdio.h>
#include <ctype.h>

int main()
{
    int n = 0;
    int a[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char ch[100];

    printf("Enter a word: ");
    fgets(ch, 100, stdin);

    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\n')
            break;

        ch[i] = toupper(ch[i]);                 // 小写转大写
        n += a[ch[i] - 65];
    }

    printf("Scrabble value: %d\n", n);

    return 0;
}