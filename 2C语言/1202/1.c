#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a < 10)
        printf("The number %d has 1 digits\n", a);
    else if (a < 100)
        printf("The number %d has 2 digits\n", a);
    else if (a < 1000)
        printf("The number %d has 3 digits\n", a);
    else
        printf("超过四位\n");
    return 0;
}