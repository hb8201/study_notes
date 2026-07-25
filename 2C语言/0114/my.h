// 避免重复包含
// my.h         __MY_H
// my_math.h    __MY_MATH_H

// 若未定义 If Not Define
#ifndef __MY_H
#define __MY_H

// 定义常量（宏）
#define N 5
// 函数声明
int max(int a, int b);
int min(int a, int b);

#endif
