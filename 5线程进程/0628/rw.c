// rw.c     读写锁
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// pthread_mutex_t mutex;
// pthread_spinlock_t spin;
pthread_rwlock_t lock;

int n = 0;
void * rd(void *)
{
    while (1)
    {
        pthread_rwlock_rdlock(&lock);
        printf("%ld 读取：%d\n", pthread_self(), n);
        sleep(1);   // 读花1s
        pthread_rwlock_unlock(&lock);
        // 设置属性就不用休眠
        // sleep(1);    // 读完等1s
    }
}
void *wr(void *)
{
    while (1)
    {
        pthread_rwlock_wrlock(&lock);
        n++;
        printf("--------写入：%d\n", n);
        sleep(5);   // 写花5s
        pthread_rwlock_unlock(&lock);
        sleep(1);   // 写完等1s
    }
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;

    pthread_rwlockattr_t attr;
    pthread_rwlockattr_init(&attr);
    pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);

    // 初始化：避免写操作 ***饿死***
    pthread_rwlock_init(&lock, &attr);

    pthread_create(&t1, NULL, rd, NULL);
    pthread_create(&t2, NULL, rd, NULL);
    pthread_create(&t3, NULL, rd, NULL);
    pthread_create(&t4, NULL, wr, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_rwlock_destroy(&lock);

    return 0;
}
