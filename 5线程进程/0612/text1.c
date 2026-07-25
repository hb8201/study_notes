// 统计一个线程计算 一亿 以内的质数所需的时间
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void *task(void *arg)
{
    int n = 0;
    for (int i = 2; i < 100000000; i++)
    {
        if (is_prime(i))
        {
            n++;
        }
    }
    int *a = malloc(sizeof(int));
    *a = n;
    return (void *)a;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, task, NULL);
    void *a;
    pthread_join(tid, &a);
    int n = *((int *)a);
    free(a);
    printf("%d\n", n);

    return 0;
}
