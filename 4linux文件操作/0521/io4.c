// io4.c
// 字符串读取
#include <stdio.h>

int main()
{
    FILE *fp = fopen("io4.c", "r");
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
        printf("%s", buf);
        c++;
    }
    printf("c = %d\n", c);
    fclose(fp);
    return 0;
}
