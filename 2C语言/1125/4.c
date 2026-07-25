#include <stdio.h>
int main()
{
    float i, j;
    printf("Enter an amount:");
    scanf("%f", &i);
    j = i * 1.05;
    printf("With tax added: $%.2f\n", j);
    return 0;
}