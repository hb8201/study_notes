#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &a, &b);
    if(a > 12)
    {
        a -= 12;
        printf("Equivalent 12-hour time: %d:%d PM\n", a, b);
    }
    else
        printf("Equivalent 12-hour time: %d:%d AM\n", a, b);
    return 0;
}