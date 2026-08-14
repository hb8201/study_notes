// tmp.c
// 泛型：带参数的宏定义
#include <string.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char const *argv[])
{
    
    printf("%d\n", MAX(2, 3));
    printf("%d\n", MAX(2>6, 3<7));
    printf("%f\n", MAX(2.3, 3.6));
    printf("%s\n", MAX("hello", "你好"));

    return 0;
}
