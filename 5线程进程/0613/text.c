// 使用多线程模式统计 Linux 内核中 .c、.h 文件的总行数
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
// 最大路径长度
#define ROUTE_LEN_MAX 1024
// 目录下最多的 .c、.h文件数
#define ROUTE_SUM_MAX 100000

pthread_mutex_t mut;

int f_c = 0;
int f_h = 0;
// 存放一个路径下所有 .c、.h 文件路径
char ROUTE_SUM[ROUTE_SUM_MAX][ROUTE_LEN_MAX];
// 现有.c、.h文件数
int FILE_SUM = 0;
// 返回字符串最后两位的值
char *name_last_2(char *ch);
// 统计单个文件 .c、.h 文件行数
void file_sum_c(char *name);
void file_sum_h(char *name);

void *task(void *route);
//线程池，4线程从 ROUTE_SUM 中读取文件路径
void xianchengchi();
// 统计一个路径下的 .c、.h 文件总行数
void route_sum(char *route);

int main(int argc, char const *argv[])
{
    route_sum("/home/hb/linux-7.0.10/");
    xianchengchi();
    printf("%d,%d\n", f_c, f_h);
    return 0;
}
char *name_last_2(char *ch)
{
    int len = 1;
    // 存两个字符 + 结束符 '\0'
    char *a = malloc(sizeof(char) * 3);
    while (1)
    {
        if (ch[len] == '\0')
        {
            sprintf(a, "%c%c", ch[len - 2], ch[len - 1]);
            break;
        }
        len++;
    }
    return a;
}
void file_sum_c(char *name)
{
    int t = 0;
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return;
    }
    char buf[4096];
    int n;
    while ((n = fgetc(fp)) != EOF)
    {
        if (n == '\n')
        {
            t++;
        }
    }
    pthread_mutex_lock(&mut);
    f_c += t;
    pthread_mutex_unlock(&mut);
    return;
}
void file_sum_h(char *name)
{
    int t = 0;
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return;
    }
    char buf[4096];
    int n;
    while ((n = fgetc(fp)) != EOF)
    {
        if (n == '\n')
        {
            t++;
        }
    }
    pthread_mutex_lock(&mut);
    f_h += t;
    pthread_mutex_unlock(&mut);
    return;
}
void *task(void *route)
{
    char *route1 = ((char *)route);
    char *c = name_last_2(route1);
    if (strcmp(c, ".h") == 0)
    {
        file_sum_h(route1);
    }
    if(strcmp(c, ".c") == 0)
    {
        file_sum_c(route1);
    }
}
void xianchengchi()
{
    int len = 0;
    pthread_mutex_init(&mut, NULL);
    while (len < FILE_SUM)
    {
        if (FILE_SUM - len < 4 && FILE_SUM - len > 0)
        {
            pthread_t *c = malloc(sizeof(pthread_t) * (FILE_SUM - len));
            for (int i = 0; i < FILE_SUM - len; i++)
            {
                if (pthread_create(&c[i], NULL, task, ROUTE_SUM[len + i]) != 0)
                {
                perror("create error\n");
                return;
                }
                len++;
            }
            for (int i = 0; i < FILE_SUM - len; i++)
            {
                pthread_join(c[i], NULL);
            }
        }
        if (FILE_SUM - len >= 4)
        {
            pthread_t tid1;
            pthread_t tid2;
            pthread_t tid3;
            pthread_t tid4;
            if (pthread_create(&tid1, NULL, task, ROUTE_SUM[len]) != 0 ||
                pthread_create(&tid2, NULL, task, ROUTE_SUM[len + 1]) != 0 ||
                pthread_create(&tid3, NULL, task, ROUTE_SUM[len + 2]) != 0 ||
                pthread_create(&tid4, NULL, task, ROUTE_SUM[len + 3]) != 0)
            {
                perror("create error\n");
                return;
            }
            pthread_join(tid1, NULL);
            pthread_join(tid2, NULL);
            pthread_join(tid3, NULL);
            pthread_join(tid4, NULL);
            len += 4;
        }
    }
    pthread_mutex_destroy(&mut);
}
void route_sum(char *route)
{
    DIR *dir = opendir(route);
    if (dir == NULL)
    {
        perror("无法打开文件夹\n");
        return;
    }
    struct dirent *d;
    while ((d = readdir(dir)) != NULL)
    {
        char ch[ROUTE_LEN_MAX];
        if (strncmp(d->d_name, ".", 1) || strncmp(d->d_name, "..", 1))
        {
            sprintf(ch, "%s/%s", route, d->d_name);
            if (d->d_type == 4)
            {
                route_sum(ch);
            }
            if (d->d_type == 8)
            {
                strcpy(ROUTE_SUM[FILE_SUM++], ch);
            }
        }
    }
    closedir(dir);
}
