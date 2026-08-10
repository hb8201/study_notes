// p2.c
// 多进程实例
#include <stdio.h>
#include <stdlib.h>

// unix std     POSIX 规范定义的标准 API
#include <unistd.h>
#include <sys/wait.h>

#define N 8

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            printf("worker: %d, %d\n", getpid(), getppid());
            sleep(20);
            exit(0);
        }
    }

    for (int i = 0; i < N; i++)
    {
        wait(NULL);
    }

    printf("master: end\n");
    
    return 0;
}
