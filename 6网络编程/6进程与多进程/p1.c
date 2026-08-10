// p1.c
// 创建子进程
#include <stdio.h>
#include <stdlib.h>

// unix std     POSIX 规范定义的标准 API
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    // 创建子进程
    int pid = fork();
    if (pid == -1)
    {
        perror("创建失败!\n");
        return -1;
    }
    if (pid == 0)
    {
        // 子进程
        printf("worker: %d\t%d\n", getpid(), getppid());
        // sleep(10);

        // execl list，传多个参数，逗号隔开
        // execv array，传数组

        // 1.路径
        // 2.程序名
        // 3.参数
        // ..NULL 标识参数结束
        // execlp("wc", "wc", "-l", "p2.c", NULL);
        // execlp("uname", "uname", "-a", NULL);

        execlp("./m1", "m1", "sdas", NULL);


        // 返回状态码
        exit(1);
    }
    else
    {
        printf("master: %d\t%d\n", getpid(), getppid());

        // 获得子进程返回的状态码
        int status;
        waitpid(pid, &status, WUNTRACED);
        if (WIFEXITED(status))
        {
            int val = WEXITSTATUS(status);
            printf("val = %d\n", val);
        }
        // wait(NULL);

        // 主进程
        // sleep(20);
        printf("pid: %d\n", pid);
    }

    return 0;
}
