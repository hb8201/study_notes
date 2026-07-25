// ptr2.c
// 常量指针与指针常量
#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;

    // 常量指针
    int const *p1 = &a;     // *p1 不可变
    p1 = &b;
    printf("%d\n", *p1);

    // 指针常量
    int * const p2 = &b;     // p2 不可变
    *p2 = a;
    printf("%d\n", b);

    // 常量指针常量
    int const *const p3 = &a;   // p3 *p3 都不可变


    return 0;
}