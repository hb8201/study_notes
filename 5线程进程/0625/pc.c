// pc.c
// 生产者、消费者模型
#include <stdio.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 队列的容量
#define MAX 5

// 队列的大小
int n = 0;

// 互斥锁
pthread_mutex_t mutex;

// 条件变量
pthread_cond_t cond_full;   // 满
pthread_cond_t cond_empty;  // 空

// 生产者
void *procuder(void *)
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        while (n == MAX)
        {
            printf("生产者：队列已满，阻塞\n");
            // 进入等待（阻塞）状态，等待收到 cond_full
            pthread_cond_wait(&cond_empty, &mutex);
        }

        n++;
        printf("生产者：生产 %d\n", n);
        // 唤醒等待特定条件的线程
        pthread_cond_signal(&cond_full);        // 只唤醒等待特定条件的一个线程
        // pthread_cond_broadcast(&cond_full);     // 唤醒等待特定条件的所有线程

        pthread_mutex_unlock(&mutex);

        // 线程主动让出处理器时间，从运行进入就绪
        sched_yield();      // 单核系统比较明显
    }
}
// 消费者
void *consumer(void *)
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        while (n == 0)
        {
            printf("消费者：队列已空，阻塞\n");
            // 进入等待（阻塞）状态，等待收到 cond_full
            pthread_cond_wait(&cond_full, &mutex);
        }

        printf("消费者：消费了 %d\n", n);
        n--;
        // 发送一个消息，唤醒等待 cond_empty 条件的线程
        pthread_cond_signal(&cond_empty);

        pthread_mutex_unlock(&mutex);

        // 线程主动让出处理器时间，从运行进入就绪
        sched_yield();
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;

    // 互斥锁初始化
    pthread_mutex_init(&mutex, NULL);
    // 条件变量初始化
    pthread_cond_init(&cond_full, NULL);
    pthread_cond_init(&cond_empty, NULL);

    pthread_create(&t1, NULL, procuder, NULL);
    pthread_create(&t2, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 销毁
    pthread_mutex_destroy(&mutex);

    pthread_cond_destroy(&cond_full);
    pthread_cond_destroy(&cond_empty);

    return 0;
}
