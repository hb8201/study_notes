// t.c
// 线程的创建与执行
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>     // unix standard

void *task(void *)
{
    for (int i = 0; i < 20; i++)
    {
        printf("子线程：%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    // 线程IB,标识, long int
    pthread_t tid;
    // pthread_attr
    // 创建子线程
    // 1.线程ID
    // 2.线程属性
    // 3.线程执行任务, 函数指针
    // 4.线程参数， 函数的参数
    int r = pthread_create(&tid, NULL, task, NULL);

    printf("是否创建成功：%d\n", r);
    printf("线程ID：%ld\n", tid);

    for (int i = 0; i < 9; i++)
    {
        printf("main 线程：%d\n", i);
        sleep(1);
    }

    // 1. 线程ID
    // 2. 接收task的返回值
    pthread_join(tid, NULL);

    return 0;
}