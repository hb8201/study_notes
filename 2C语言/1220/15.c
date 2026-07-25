#include <stdio.h>

int main()
{
    int a;
    char ch[100];
    printf(" Enter messgae to be encrypted: ");
    fgets(ch, 100, stdin);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &a);
    printf("Encrypted message: ");

    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\n')
            break;
        if (ch[i] >= 65 && ch[i] <= 90)
        {
            if (ch[i] + a > 90)
                ch[i] = ch[i] + a - 26;
            else
                ch[i] += a;
        }
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            if (ch[i] + a > 122)
                ch[i] = ch[i] + a - 26;
            else
                ch[i] += a;
        }
    }

    printf("%s", ch);

    return 0;
}