// 实现同时连接多个客户端（多线程）
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>

void *task(void *p)
{
    int c_fd = *((int *)p);

    while (1)
    {
        // 读
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        read(c_fd, buf, sizeof(buf));
        if (buf[0] == '\0') continue;
        printf("客户端%d收到：%s\n", c_fd, buf);

        if (strcmp(buf, "ok\r\n") == 0)
            break;
        // 写
        char msg[] = "TCP Server!\n";
        write(c_fd, msg, sizeof(msg));
    }
    close(c_fd);
}

int main(int argc, char const *argv[])
{
    
    // 创建服务器套接字，返回一个文件描述符
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("出错\n");
    }

        // 绑定地址之前设置
    // 套接字参数设置：地址复用
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    // 创建服务器地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // 绑定地址
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    
    // 监听
    listen(fd, 9);
    printf("服务器准备就绪\n");

    while (1)
    {
        printf("等待连接...\n");
        // 记录客户端地址
        struct sockaddr_in c_addr;
        int size = sizeof(c_addr);
        memset(&c_addr, 0, size);
    
        // 申请连接
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &size);

        // 创建线程
        pthread_t t1;
        pthread_create(&t1, NULL, task, &c_fd);
        pthread_detach(t1);
    }
    close(fd);

    return 0;
}
