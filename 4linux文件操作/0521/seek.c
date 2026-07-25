// seek.c
// 任意访问
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    // 文件大小
    char *buf = malloc(size);
    rewind(fp);     // 移到末尾还要回到开头
    fread(buf, 1, size, fp);
    printf("%s", buf);

    // fseek(fp, 4, SEEK_SET);         // 从开始跳过4个开始
    // int ch = fgetc(fp);
    // printf("%c\n", ch);
    // rewind(fp);     // 回到文件开头
    // ch = fgetc(fp);
    // printf("%c\n", ch);

    // 跳到文件末尾
    // fseek(fp, 0, SEEK_END);      // 从末尾跳过0个开始读
    // long size = ftell(fp);       // 获得当前位置距离文件开头的字节数
    // printf("%ld\n", size);

    fclose(fp);
    return 0;
}