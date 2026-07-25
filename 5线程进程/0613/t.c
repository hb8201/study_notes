// t.c  非分离态
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 入口函数
void *task(void *p)
{
    // 动态分配堆空间
    int *val = malloc(sizeof(int));
    pthread_t tid = pthread_self();
    for (int i = 0; i < 9; i++)
    {
        printf("------------%ld %d\n", tid, i);
        if (i == 5)
        {
            // 退出并返回值
            *val = 5;
            pthread_exit((void *)val);
        }
    }
    *val = 9;
    return (void *)val;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    if (pthread_create(&tid, NULL, task, NULL) != 0)
    {
        perror("create error\n");
        return 1;
    }
    // MAIN
    printf("sub：%ld\n", tid);

    // sleep(2)
    void *val;
    pthread_join(tid, &val);
    int v = *((int *)val);
    printf("子线程返回参数：%d\n", v);
    free(val);

    // MAIN
    // pthread_exit(NULL);     // 退出主线程，后面不执行
    // 取消指定 ID 的线程
    // pthread_cancel(tid);
    printf("mian：%ld\n", pthread_self());

    return 0;
}
