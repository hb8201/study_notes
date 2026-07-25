// uni.c
// union
#include <stdio.h>
#include <string.h>

union u
{
    char a;
    short b;
    int c;
};

int main()
{
    union u u1;
    u1.a = 'y';
    printf("%c\n", u1.a);
    u1.b = 30000;
    printf("%c\n", u1.a);
    printf("%d\n", u1.b);
    u1.c = 80000;
    printf("%c\n", u1.a);
    printf("%d\n", u1.b);
    printf("%d\n", u1.c);

    return 0;
}