// server.c
// TPC 服务器
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

// 本地通信地址
#include <sys/un.h>
// 网络通信地址
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
    // 创建服务端套接字
    // 1.地址族，选择协议：AF_UNIX(AF_LOCAL), AF_INET6
    // 2.套接字类型：SOCK_STREAM 流 TCP,SOCK_DGRAM 数据报 UDP
    // 3.协议 0
    // 返回一个文件描述符
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("出错\n");
    }

    // 创建服务器地址
    // struct sockaddr
    // struct sockaddr_in6
    // struct sockaddr_un
    struct sockaddr_in addr;
    // 用0填充 addr 所在的空间
    memset(&addr, 0, sizeof(addr));
    // 协议族：TCP/IP IPv4
    addr.sin_family = AF_INET;
    // IP：无符号32位整数   0.0.0.0
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 端口号：2字节：无符号短整型
    addr.sin_port = htons(9000);

    // 绑定地址
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    // 监听
    listen(fd, 9);
    printf("服务器准备就绪\n");

    int flag = 1;
    while (flag)
    {
        // 接受客户端请求
        printf("等待连接...\n");

        // 记录客户端地址
        struct sockaddr_in c_addr;
        memset(&c_addr, 0, sizeof(c_addr));
        int len = sizeof(c_addr);

        // 建立了一个连接
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &len);
        // 读写数据：在新的线程中异步执行

        char buf[1024];
        memset(buf, 0, 1024);
        int size = read(c_fd, buf, 1024);
        printf("收到：%s\n", buf);

        char msg[] = "TCP Server!\n";
        write(c_fd, msg, sizeof(msg));

        //
        close(c_fd);
    }
    //
    close(fd);

    return 0;
}
