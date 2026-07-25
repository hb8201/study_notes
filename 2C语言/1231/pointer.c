// pointer.c
#include <stdio.h>

// 函数传值调用
// 值：基本类型，复制了一份
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int a = 2;
    int b = 3;
    swap(&a, &b);
    printf("%d, %d\n", a, b);


    // char c = 'c';
    // int i = 42;
    // double d = 3.1415;
    // printf("%lu\n", sizeof(c));   // sizeof 是运算符，不是函数
    // printf("%lu\n", sizeof(i));
    // printf("%lu\n", sizeof(d));

    // // 可以存所有类型的首地址，但不能通过p去修改它指向空间的值（但不能解引用）
    // void *p;
    // p = &c;
    // p = &i;
    // p = &d;

    // char *p1 = &c;          // char *p1;    p1 = &c;
    // int *p2 = &i;
    // double *p3 = &d;
    // printf("指针大小：%lu， 指针的值：%p， 指针指向空间的数据的值：%c\n", sizeof(p1), p1, *p1);
    // printf("指针大小：%lu， 指针的值：%p， 指针指向空间的数据的值：%d\n", sizeof(p2), p2, *p2);
    // printf("指针大小：%lu， 指针的值：%p， 指针指向空间的数据的值：%f\n", sizeof(p3), p3, *p3);

    // printf("%c\n", c);
    // *p1 = 'x';
    // printf("%c\n", c);

    return 0;
}