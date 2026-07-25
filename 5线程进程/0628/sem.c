// sem.c
// 计数信号量
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// 线程的最大数量
#define MAX 9
// 可以数量
#define N 3

sem_t sem;

void *task(void *p)
{
    int id = *((int *)p);
    free(p);

    // 获得资源
    // sem > 0  ->  sem--
    // sem = 0  ->  阻塞
    sem_wait(&sem);
    printf("线程%d 启动\n", id);
    sleep(3);
    printf("线程%d 结束 ~~~\n", id);
    // 释放资源 sem++
    sem_post(&sem);
}

int main(int argc, char const *argv[])
{
    sem_init(&sem, 0, N);
    
    pthread_t tid[MAX];

    for (int i = 0; i < MAX; i++)
    {
        // 动态分配堆空间
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&tid[i], NULL, task, id);
    }

    for (int i = 0; i < MAX; i++)
    {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem);

    return 0;
}
