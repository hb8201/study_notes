// m1.c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("参数不足\n");
        return 1;
    }
    printf("这是另一个程序: %s\n", argv[1]);
    return 0;
}
