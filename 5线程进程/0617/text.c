// 模拟售票窗口
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// 窗口数量
#define MAX 4

int count = 1000;
pthread_mutex_t mut;

int x(int a)
{
    int i = a;
    while (i > 10)
    {
        i /= 10;
        i %= 10;
    }
    return i;
}

void *task(void *n)
{
    int j = *((int *)n);
    int i = 0;
    while (count > 0)
    {
        pthread_mutex_lock(&mut);
        i = ((x(count) * 2) + j) / x(count);
        count -= i;
        printf("%d窗口：售出%d张，还剩余：%d张票\n", j + 1, i, count);
        pthread_mutex_unlock(&mut);

        sleep(1);
    }
    free(n);
}
// void *task(void *n)
// {
//     int i = 0;
//     int j = *((int *)n);
//     while (i < (1000 / MAX))
//     {
//         printf("%d窗口：售出1张，还剩余：%d张票\n", j + 1, count - i);
//         i++;
//     }
//     pthread_mutex_lock(&mut);
//     count -= i;
//     pthread_mutex_unlock(&mut);
//     free(n);
// }

int main(int argc, char const *argv[])
{
    pthread_t *t = malloc(sizeof(pthread_t) * MAX);
    pthread_mutex_init(&mut, NULL);
    for (int i = 0; i < MAX; i++)
    {
        int *j = malloc(sizeof(int));
        *j = i;
        void *k = j;
        if (pthread_create(&t[i], NULL, task, k) != 0)
        {
            perror("线程创建失败\n");
            return 1;
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        pthread_join(t[i], NULL);
    }
    pthread_mutex_destroy(&mut);
    printf("卖完了\n");

    return 0;
}
