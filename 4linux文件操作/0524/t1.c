// 切分a.txt文件
#include <stdio.h>
#include <stdlib.h>

void p(FILE *a, FILE *b);
void w(int a);

int main()
{
    FILE *fp = fopen("a.txt", "r");
    fseek(fp, 0, SEEK_END);
    int a = ftell(fp);
    rewind(fp);
    int b = a / (1024 * 10000) + 1 + 1;
    // 第一个 +1 将少于1024 * 10000 放入，第二个 +1 用于观察最后一个文件是否是空的
    w(b);
    fclose(fp);

    return 0;
}
void p(FILE *a, FILE *b)
{
    if (a == NULL || b == NULL)
    {
        perror("无法打开文件\n");
        return;
    }
    char buf[1024 * 1000];
    int n, i;
    i = 0;
    while (i != 10)
    {
        n = fread(buf, 1, sizeof(buf), a);
        fwrite(buf, 1, n, b);
        i++;
    }
}
void w(int a)
{
    FILE *fp = fopen("a.txt", "r");
    char ch1[20], ch2[20];
    for (int i = 1; i <= a; i++)
    {
        sprintf(ch1, "out%d", i);
        sprintf(ch2, "a%d.txt", i);
        FILE *ch1 = fopen(ch2, "w");
        p(fp, ch1);
        fclose(ch1);
    }
    fclose(fp);
}