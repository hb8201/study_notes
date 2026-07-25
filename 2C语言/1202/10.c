#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter numberical grade:");
    scanf("%d", &a);

    if (a < 0 || a > 100)
        printf("ERROR\n");
    else
    {
        b = a / 10;
        switch (b)
        {
        case 10:
        case 9: printf("Letter grade: A\n"); break;
        case 8: printf("Letter grade: B\n"); break;
        case 7: printf("Letter grade: C\n"); break;
        case 6: printf("Letter grade: D\n"); break;
        default: printf("Letter grade: F\n"); break;
        }
    }

    return 0;
}