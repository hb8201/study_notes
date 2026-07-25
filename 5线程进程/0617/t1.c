// t1.c         多线程访问一个全局变量
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 多个线程同时访问，数据可能会不同步
int count = 0;

// 互斥锁
pthread_mutex_t mut;

void *task(void *)
{
    int t = count;
    for (int i = 0; i < 1000000; i++)
    {
        t++;
    }
    // 上锁
    pthread_mutex_lock(&mut);
    count += t;
    // 解锁
    pthread_mutex_unlock(&mut);
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    // 初始化互斥锁
    // 1 互斥锁     2 属性
    pthread_mutex_init(&mut, NULL);

    // 异步执行 create
    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);
    pthread_create(&t3, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    // 销毁互斥锁
    pthread_mutex_destroy(&mut);

    // join 完后同步
    printf("%d\n", count);

    return 0;
}
