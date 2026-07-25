// 二进制复制

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *in = fopen("io1.c", "rb");
    FILE *out = fopen("bin.c", "wb");
    if (in == NULL || out == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    //
    char buf[32];
    int n;
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
    {
        fwrite(buf, 1, n, out);
    }
    fclose(in);
    fclose(out);

    return 0;
}