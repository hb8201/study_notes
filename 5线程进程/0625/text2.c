// 使用信号量实现生产者消费者模型
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// 总车流量
#define CL_MAX 20

// 停车场车位数量
#define CW_MAX 10

// 停车场入口数量
#define RK_MAX 3

// 停车场出口数量
#define CK_MAX 2

// 停车场内现有车辆数量
int n = 0;

// 统计总入库车辆
int i = 0;
// 统计总出库车辆
int j = 0;

// 互斥锁
sem_t mutex;

// 条件变量
sem_t full;
sem_t empty;


void *procuder(void *p)
{
    int *P = (int *)p;
    while (1)
    {
        sem_wait(&mutex);
        if (i >= CL_MAX)
        {
            sem_post(&mutex);
            break;
        }
        sem_post(&mutex);

        sem_wait(&empty);

        sem_wait(&mutex);
        if (i >= CL_MAX)
        {
            sem_post(&mutex);
            sem_post(&empty);
            break;
        }
        n++;
        i++;
        printf("入口%d：车辆入库，停车场已停车辆：%d\n", *P, n);
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *p)
{
    int *P = (int *)p;
    while (1)
    {
        sem_wait(&mutex);
        if (j >= CL_MAX)
        {
            sem_post(&mutex);
            break;
        }
        sem_post(&mutex);

        sem_wait(&full);

        sem_wait(&mutex);
        if (j >= CL_MAX)
        {
            sem_post(&mutex);
            sem_post(&full);
            break;
        }
        n--;
        j++;
        printf("出口%d：车辆出库，停车场已停车辆：%d\n", *P, n);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1[RK_MAX];
    pthread_t t2[CK_MAX];

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, CW_MAX);

    for (int i = 0; i < RK_MAX; i++)
    {
        int *p = malloc(sizeof(int));
        *p = i + 1;
        pthread_create(&t1[i], NULL, procuder, p);
    }
    for (int i = 0; i < CK_MAX; i++)
    {
        int *p = malloc(sizeof(int));
        *p = i + 1;
        pthread_create(&t2[i], NULL, consumer, p);
    }

    for (int i = 0; i < RK_MAX; i++)
    {
        pthread_join(t1[i], NULL);
    }
    for (int i = 0; i < CK_MAX; i++)
    {
        pthread_join(t2[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
