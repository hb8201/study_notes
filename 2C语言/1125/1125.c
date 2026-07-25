// 1125.c
// 函数：名称、参数列表、函数体、返回值
#include <stdio.h>

// const 标记常量，声明时初始化，之后不可以赋值
// 全局、局部
// const int n = 1;

int main()
{
    //----------------------------------- 存储范围与溢出
    // 1byte 8bit 256
    // 无符号数：0 ~ 255
    // 有符号数：-128 ~ 127
    // char c1 = 127;
    // char c2 = -128;
    // unsigned char c3 = 255;

    // 2byte 16bit 65536
    // short s1 = -32768;
    // short s2 = 32767;
    // unsigned short rmb = 1 - 6;
    // printf("c = %d\n", rmb);

    // float f1 = 3.14f;
    // double f2 = 2.0 / 3;
    // printf("%f\n", f2);
    int a = 2;
    int b = 3;
    // 1
    // int t = a;
    // a = b;
    // b = t;
    // 2 溢出结果依然正确
    a = a + b; // (a + b)  b
    b = a - b; // (a + b)  a
    a = a - b; // b        a
    printf("%d, %d\n", a, b);
    // 3 交换两个变量的值

    // ----------------------------------
    /*
    // char,short,int,long,long long
    // 类型 标识符（变量名）
    // 声明、初始化、赋值
    char n1 = 100;         // 10, 0~9
    char n2 = 0144;        // 8, 0~7
    char n3 = 0x64;        // 16, 0~9 A~F
    char n4 = 0b1100100;   // 2, 01

    // %d, %0, %x, %b
    printf("%d\n", n1);
    printf("%#o\n", n2);
    printf("%#x\n", n3);
    printf("%#b\n", n4);

    int n5 = 78;
    printf("%d, %#o, %#x, %#b\n", n5, n5, n5, n5);
    */

    return 0;
}