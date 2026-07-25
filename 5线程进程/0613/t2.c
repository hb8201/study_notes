// t2.c     分离态
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *task(void *p)
{
    int v = *((int *)p);
    for (int i = 1; i <= v; i++)
    {
        printf("%ld: %d\n", pthread_self(), i);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    // 线程 ID
    pthread_t tid;
    // 方案一
    // 线程属性
    pthread_attr_t *attr;
    pthread_attr_init(attr);
    // 分离态的子线程：后台执行，异步执行，资源管理 自动释放资源;不返回数据
    pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);

    int n = 9;
    if (pthread_create(&tid, attr, task, &n))
    {
        perror("create error\n");
        return 1;
    }
    // 释放属性
    pthread_attr_destroy(attr);

    printf("sub: %ld\n", tid);

    pthread_exit(NULL);
    // 不可到达
    printf("main:%ld\n", pthread_self());

    // // 方案二
    // pthread_create(&tid, NULL task, NULL);
    // pthread_detach(tid);

    // 不可 join，不能返回值
    // pthread_join()；
    
    return 0;
}
