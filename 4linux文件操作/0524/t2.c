// 统计目录中文件数、目录数、所有文件总行数  (不包含隐藏文件)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void t(char *ch, int *a, int *b, long *c);
int hangshu(char *ch);

int main()
{
    char *lj = "/home/hb/linux-7.0.10/";    // /home/hb/linux-7.0.10/
    int a = 0, b = 0;
    long c = 0;
    t(lj, &a, &b, &c);
    FILE *fp = fopen("t3.c", "w");
    char ch[1024];
    sprintf(ch, "// 文件数量：%d\n// 文件夹数量：%d\n// 文件总行数：%ld\n", a, b, c);
    fputs(ch, fp);
    fclose(fp);

    return 0;
}
int hangshu(char *ch)
{
    FILE *fp = fopen(ch, "r");
    char a;
    int b = 0;
    while ((a = fgetc(fp)) != EOF)
    {
        if (a == '\n')
            b++;
    }
    fclose(fp);
    return b;
}
void t(char *ch, int *a, int *b, long *c)
{
    DIR *dir = opendir(ch);
    if (dir == NULL)
    {
        perror("无法打开目录\n");
        return;
    }
    struct dirent *d;
    while ((d = readdir(dir)) != NULL)
    {
        if (strncmp(d->d_name, ".", 1) || strncmp(d->d_name, "..", 1))
        {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", ch, d->d_name);
            if (d->d_type == 4)
            {
                (*b)++;
                t(path, a, b, c);
            }
            if (d->d_type == 8)
            {
                int i = hangshu(path);
                if (i > 0)
                    *c += i;
                (*a)++;
            }
        }
    }
    closedir(dir);
    return;
}