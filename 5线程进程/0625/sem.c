// sem.c    信号量
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
// 信号量头文件
#include <semaphore.h>

// 信号量
sem_t sem;
// sem_t sem_sum;

int n = 0;
void *task(void *)
{
    for (int i = 0; i < 100000; i++)
    {
        // 先判断信号值是否为 1，为 1 执行后续，并且信号值 -1；否则阻塞
        sem_wait(&sem);
        n++;
        // 信号值 +1
        sem_post(&sem);
    }
}

int main(int argc, char const *argv[])
{
    // 1.信号量本身
    // 2.线程间还是进程间：0 一个进程内，1 多个进程之间
    // 3.信号量的初始值：1 二元信号量，其他值 计数器信号量
    sem_init(&sem, 0, 1);
    // sem_init(&sem_sum, 0, 9);

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
    // sem_destroy(&sem_sum);
    printf("%d\n", n);

    return 0;
}
