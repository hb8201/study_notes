// spin.c   自旋锁
// 启用 POSIX 2008 09
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 自旋锁
pthread_spinlock_t spin;
// 互斥锁
pthread_mutex_t mutex;

int n = 0;
void *task(void *)
{
    // volatile     明确在使用声明的变量的同时也要使用互斥锁或者自旋锁
    // 避免被编译器优化（写入寄存器），直接从寄存器、内存读取
    volatile int t = n;
    for (int i = 0; i < 1000000; i++)
    {
        t++;
    }
    // pthread_spin_lock(&spin);
    pthread_mutex_lock(&mutex);
    n += t;
    pthread_mutex_unlock(&mutex);
    // pthread_spin_unlock(&spin);
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    pthread_spin_init(&spin, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);
    pthread_create(&t3, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_spin_destroy(&spin);
    pthread_mutex_destroy(&mutex);

    printf("%d\n", n);

    return 0;
}
