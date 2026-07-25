// io2.c
// 字符写
#include <stdio.h>

int main()
{
    FILE *fp = fopen("b.txt", "a");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    // 写
    fputc('a', fp);
    // 关闭
    fclose(fp);

    return 0;
}