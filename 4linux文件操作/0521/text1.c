// 实现 wc 的核心功能    显示 输出行 单词 字节
#include <stdio.h>

int main()
{
    FILE *in = fopen("io1.c", "r");
    FILE *out = fopen("t1.c", "w");
    FILE *fp = fopen("t1.c", "r");
    if (in == NULL || out == NULL || fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    int i, j, k = 0;       // k 判断上一个是否是 \n
    int a = 0, b = 0, c = 0;    // 输出行 单词 字节

    while ((i = fgetc(in)) != EOF)
    {
        c++;
    }

    in = fopen("io1.c", "r");
    while ((i = fgetc(in)) != EOF)
    {
        if (k == 1 && (i == ' ' || i == '\n'))
        {
            if (i == '\n')
                a++;
            continue;
        }
        k = 0;
        if (i == '\n')
        {
            a++;
            k = 1;
        }
        fputc(i, out);
    }
    // ⚠️ 用完了就关闭
    fclose(in);
    fclose(out);

    while ((j = fgetc(fp)) != EOF)
    {
        if (j == '\n' || j == ' ')
        {
            b++;
        }
    }
    printf("%d %d %d\n", a, b, c);
    fclose(fp);

    return 0;
}