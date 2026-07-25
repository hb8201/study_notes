#include <stdio.h>

#define N 50

int main()
{
    char a[N];
    int i;

    printf("Enter message: ");
    fgets(a, N, stdin);
    printf("In B1FF-speak: ");

    while (a[i] != '\0')
    {
        if (a[i] >= 97 && a[i] <= 122)
            a[i] -= 32;
        
        switch (a[i])
        {
        case 'A': a[i] = '4'; break;
        case 'B': a[i] = '8'; break;
        case 'E': a[i] = '3'; break;
        case 'I': a[i] = '1'; break;
        case 'O': a[i] = '0'; break;
        case 'S': a[i] = '5'; break;
        default: break;
        }
        i++;
    }

    for (int j = i - 1; j < i + 9; j++)
        a[j] = '!';

    printf("%s\n", a);

    return 0;
}