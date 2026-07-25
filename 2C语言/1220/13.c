#include <stdio.h>

int main()
{
    char ch[100];

    printf("Enter a first and last name: ");
    fgets(ch, 100, stdin);
    printf("You enered the name: ");

    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\n')
            break;

        if (ch[i] == ' ')
        {
            for (int j = i + 1; j < 100; j++)
            {
                if (ch[j] == '\n')
                    break;
                
                printf("%c", ch[j]);
            }
        }
    }

    printf(", %c.\n", ch[0]);

    return 0;
}