// endian.c
// Big Endian
// Little Endian
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 4字节
    // 小端对齐
    int n = 0x12345678;
    // p -> n 的第一个字节
    char *p = (char *)&n;
    // %x 格式化十六进制， # 是额外显示 0x
    printf("%p, %#x\n", p, *p); // 0x78
    p++;
    printf("%p, %#x\n", p, *p); // 0x56
    p++;
    printf("%p, %#x\n", p, *p); // 0x34
    p++;
    printf("%p, %#x\n", p, *p); // 0x12

    return 0;
}
