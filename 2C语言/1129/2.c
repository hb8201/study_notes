#include <stdio.h>

int main()
{
    int a, y, m, d;
    float b;
    printf("Enter item number:");
    scanf("%d", &a);
    printf("Enter unit price:");
    scanf("%f", &b);
    printf("Enter pruchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &d, &m, &y);
    printf("Item\tUnit\t\tPurchase\n\tPrice\t\tDate\n%d\t$%7.2f\t%d/%d/%d\n", a, b, d, m, y);
    return 0;
}