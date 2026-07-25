// server.c
// 服务器
// socker - bind - listen - accept - read/write - close
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // 读写
#include <sys/socket.h> // 套接字
#include <netinet/in.h>
#include <arpa/inet.h>  // 大小端转换

int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // 绑定地址之前设置
    // 套接字参数设置：地址复用
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);

    // bind
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    listen(fd, 9);
    printf("服务器启动...\n");

    while (1)
    {
        // 客户端地址
        struct sockaddr_in c_addr;
        memset(&c_addr, 0, sizeof(c_addr));
        int len = sizeof(c_addr);

        // 建立 TCP 连接
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &len);

        // 获得客户端端口
        int port = ntohs(c_addr.sin_port);

        // 获得客户端 IP
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &c_addr.sin_addr, ip, INET_ADDRSTRLEN);
        printf("连接：%s:%d\n", ip, port);

        while (1)
        {
            // 读写
            char buf[1024];
            memset(buf, 0, sizeof(buf));
            read(c_fd, buf, sizeof(buf));

            // 读取为空，继续读取
            if (buf[0] == '\0') continue;
            printf("收到：%s\n", buf);
            if (strncmp(buf, "bye", 3) == 0)
            {
                char msg[] = "bye\n";
                write(c_fd, msg, sizeof(msg));
                break;
            }
    
            char msg[] = "ok\n";
            write(c_fd, msg, sizeof(msg));
        }
        // 关闭
        printf("关闭：%s:%d\n", ip, port);
        close(c_fd);
    }
    close(fd);

    return 0;
}

