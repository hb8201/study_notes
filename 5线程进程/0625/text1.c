// 模拟停车场，多个入口和出口（使用生产者消费者模型实现）
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
pthread_mutex_t mutex;

// 条件变量
pthread_cond_t cond_full;
pthread_cond_t cond_empty;

void *procuder(void *p)
{
    int *P = (int *)p;
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (i >= CL_MAX)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        while (n == CW_MAX)
        {
            printf("停车场车位已满!\n");
            pthread_cond_wait(&cond_empty, &mutex);
        }
        // 双重校验
        if (i >= CL_MAX)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        n++;
        i++;
        printf("入口%d：车辆入库，停车场已停车辆：%d\n", *P, n);
        pthread_cond_broadcast(&cond_full);

        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *p)
{
    int *P = (int *)p;
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (j >= CL_MAX)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }

        while (n == 0)
        {
            if (j >= CL_MAX)
                break;
            printf("停车场已空!\n");
            pthread_cond_wait(&cond_full, &mutex);
        }
        n--;
        j++;
        printf("出口%d：车辆出库，停车场已停车辆：%d\n", *P, n);
        pthread_cond_broadcast(&cond_empty);

        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1[RK_MAX];
    pthread_t t2[CK_MAX];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_full, NULL);
    pthread_cond_init(&cond_empty, NULL);

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

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_full);
    pthread_cond_destroy(&cond_empty);

    return 0;
}
