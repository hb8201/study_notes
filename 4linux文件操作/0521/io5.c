// io5.c
// 字符串读写
#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%d %s\n", i, argv[i]);
    }
    if (argc != 3)
    {
        printf("请加上两个参数：源和目标\n");
        return 1;
    }



    FILE *fp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (!fp)
    {
        perror("无法打开文件\n");
        return 1;
    }
    // 缓冲区
    int c = 0;
    char buf[1024];
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        fputc(c + '1', out);
        fputs(buf, out);
        c++;
    }
    printf("c = %d\n", c);
    fclose(fp);
    return 0;
}
