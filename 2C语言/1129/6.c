#include <stdio.h>

int main()
{
    int a, b, c, d, e, f;
    printf("Enter two fractions separted by a plus sign:");
    scanf("%d/%d+%d/%d", &a, &b, &c, &d);
    e = a * d + b * c;
    f = b * d;
    printf("The sun is %d/%d\n", e, f);
    return 0;
}