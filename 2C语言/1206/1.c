#include <stdio.h>

int main()
{
    float number, max = 0.0;

    do
    {
        printf("Enter a number:");
        scanf("%f", &number);
        if (number > max)
            max = number;
    } while (number > 0);

    printf("The largest number entered was %f\n", max);

    return 0;
}