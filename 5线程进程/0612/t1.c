// t1.c
// 创建多个线程
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

typedef struct par
{
    int start;      // IN
    int end;        // IN
    int count;      // OUT
} Par;

// 判断参数n是否为质数
bool is_prime(int n)
{
    bool flag = true;
    // 2 ~ n - 1
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void *task1(void *arg)
{
    // 将 void 强行转为 int
    // int *p = (int *)arg;
    // 解引用强行转还成 int 的指针
    int p = *((int *)arg);
    // 局部变量在栈空间
    int c = 0;
    for (int i = 2; i < p; i++)
    {
        if (is_prime(i))
        {
            printf("%d,", i);
            c++;
        }
    }
    printf("\b \n");
    // 动态分配空间
    // 避免返回了局部变量的地址，出现野指针问题
    int *r = malloc(sizeof(int));
    *r = c;
    return (void *)r;
}
void *task2(void *arg)
{
    Par *p = (Par *)arg;

    for (int i = p->start; i <= p->end; i++)
    {
        if (is_prime(i))
        {
            printf("%d,", i);
            p->count++;
        }
    }
    printf("\b \n");
}
void *task3(void *)
{
    for (int i = 0; i < 16; i++)
    {
        printf("%ld：欢呼 鼓掌\n", pthread_self());
        sleep(1);
    }
}
int main()
{
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    // // 数据：基本类型、结构体
    // int n = 20;
    // pthread_create(&t1, NULL, task1, &n);

    // Par p = {1000, 2000};
    Par *p = malloc(sizeof(Par));
    p->start = 1;
    p->end = 20;
    p->count = 0;
    pthread_create(&t2, NULL, task2, p);
    // pthread_create(&t3, NULL, task3, NULL);

    // // 模板编程、泛型
    // void *r;
    // // 第二个参数是二级指针, 接收 task1 返回的数据
    // pthread_join(t1, &r);
    // int result = *((int *)r);
    // free(r);
    // printf("个数：%d\n", result);

    pthread_join(t2, NULL);
    // pthread_join(t3, NULL);

    return 0;
}