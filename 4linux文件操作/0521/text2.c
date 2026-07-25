// 统计 C 源文件的总行数、空行数、注释行、代码行
#include <stdio.h>

int main()
{
    FILE *in = fopen("io1.c", "r");
    FILE *out = fopen("t2.c", "w");
    FILE *fp = fopen("t2.c", "r");
    if (in == NULL || out == NULL || fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    int i, j, k = 0;       // k 判断上一个是否是 \n
    int a = 0, b = 0, c = 0;    // 输出行 空行 注释行

    in = fopen("io1.c", "r");
    while ((i = fgetc(in)) != EOF)
    {
        if (k == 1 && (i == ' ' || i == '\n'))
        {
            if (i == '\n')
            {
                a++;
                b++;
            }
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
    fclose(in);
    fclose(out);

    k = 1;          // 因为首行可能为注释行，所以设置为1
    while ((j = fgetc(fp)) != EOF)
    {
        if (k == 1 && j == '/')
            c++;
        k = 0;
        if (j == '\n')
            k = 1;
    }
    fclose(fp);
    printf("%d %d %d %d\n", a, b, c, a - b- c);

    return 0;
}