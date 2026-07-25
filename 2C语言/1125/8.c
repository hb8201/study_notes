#include <stdio.h>
int main()
{
    float w1, w2, w3, x, y, z;
    printf("Enter amount of loan:");
    scanf("%f", &x);
    printf("Enter interset rate:");
    scanf("%f", &y);
    printf("Enter monthly payment:");
    scanf("%f", &z);
    w1 = x - z + (x * y) / 1200;
    w2 = w1 - z + (w1 * y) / 1200;
    w3 = w2 - z + (w2 * y) / 1200;
    printf("Balance remaining after first payment: $%.2f\n", w1);
    printf("Balance remaining after second payment: $%.2f\n", w2);
    printf("Balance remaining after after payment: $%.2f\n", w3);
    return 0;
}