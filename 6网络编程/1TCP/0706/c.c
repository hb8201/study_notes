// client.c
// 客户端
// socket - connect - read/write - close

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // 读写
#include <sys/socket.h> // 套接字
#include <netinet/in.h> // IP地址
#include <arpa/inet.h>  // 大小端转换

int main(int argc, char const *argv[])
{
    // 协议族：TCP/IP，套接字类型：流 TCP
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // 服务器地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);    // 主机字节序转网络字节序：小端 -> 大端
    // 主机字节序到网络字节序的转换
    inet_pton(AF_INET, "192.168.121.130", &addr.sin_addr);    // 将 "127.0.0.1" 写到 addr.sin_addr

    // 0 成功
    connect(fd, (struct sockaddr *)&addr, sizeof(addr));

    // 读写：业务逻辑、协议规则
    // Telnet
    char buf[1024];

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        printf("：");
        // 从标准输入 stdin 获取数据写入 buf
        fgets(buf, sizeof(buf), stdin);
        // 发送，写的长度：字符串大小？buf大小
        size_t len = write(fd, buf, sizeof(buf));

        if (strncmp(buf, "bye", 3) == 0)
        {
            break;
        }

        // 读取
        memset(buf, 0, sizeof(buf));
        len = read(fd, buf, sizeof(buf));
        printf("回复：%s\n", buf);
    }

    // 关闭套接字
    close(fd);

    return 0;
}
