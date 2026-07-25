#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch1[100];
    char ch2[100];
    int n[26] = {0};
    int a;

    printf("Enter first word: ");
    fgets(ch1, 100, stdin);
    printf("Enter second word: ");
    fgets(ch2, 100, stdin);

    for (int i = 0; i < 100; i++)
    {
        if (ch1[i] == '\n')
            break;
        ch1[i] = tolower(ch1[i]);           // 大写转小写
        if (isalpha(ch1[i]))                // 判断ch1[i]是否为26字母
            n[ch1[i] - 97] += 1;
    }

    for (int i = 0; i < 100; i++)
    {
        if (ch2[i] == '\n')
            break;
        ch2[i] = tolower(ch2[i]);           // 大写转小写
        if (isalpha(ch2[i]))                // 判断ch1[i]是否为26字母
            n[ch2[i] - 97] -= 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (n[i] == 0)
            a += 1;
    }

    if (a == 26)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}