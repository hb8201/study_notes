// io3.c
// 复制
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *in = fopen("io1.c", "r");
    FILE *out = fopen("io.txt", "w");
    if (in == NULL || out == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    // 
    int ch;
    while ((ch = fgetc(in)) != EOF)
    {
        // 判断是否是字母    isalpha()
        if (isalnum(ch))    // 字母和数字
        {
            ch++;
        }

        fputc(ch, out);
    }
    printf("OK\n");
    fclose(in);
    fclose(out);


    return 0;
}