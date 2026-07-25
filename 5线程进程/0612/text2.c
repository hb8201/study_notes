// 创建多个线程统计时间
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct par
{
    int start;
    int end;
    int count;
} Par;

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
    Par *p = (Par *)arg;
    for (int i = p->start; i <= p->end; i++)
    {
        if (is_prime(i))
        {
            p->count++;
        }
    }
}

int main(int argc, char const *argv[])
{
    Par p1 = {2, 12500000, 0};
    Par p2 = {12500001, 25000000, 0};
    Par p3 = {25000001, 32500000, 0};
    Par p4 = {32500001, 50000000, 0};
    Par p5 = {50000001, 62500000, 0};
    Par p6 = {62500001, 75000000, 0};
    Par p7 = {75000001, 87500000, 0};
    Par p8 = {87500001, 100000000, 0};
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;
    pthread_t t6;
    pthread_t t7;
    pthread_t t8;
    pthread_create(&t1, NULL, task, &p1);
    pthread_create(&t2, NULL, task, &p2);
    pthread_create(&t3, NULL, task, &p3);
    pthread_create(&t4, NULL, task, &p4);
    pthread_create(&t5, NULL, task, &p5);
    pthread_create(&t6, NULL, task, &p6);
    pthread_create(&t7, NULL, task, &p7);
    pthread_create(&t8, NULL, task, &p8);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);

    printf("%d\n", p1.count + p2.count + p3.count + p4.count + p5.count + p6.count + p7.count + p8.count);

    return 0;
}
