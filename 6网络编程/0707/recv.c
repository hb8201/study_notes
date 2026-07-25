// recv.c
// 接收方
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);

    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 创建接收方地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9527);

    // bind
    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    // 接收
    // UDP 理论最大 65535， 4/8
    // IP MTU(最大传输单元) 1500， 20
    // 固定最大值 1500 - 8 - 20
    char buf[1500 - 28];

    // 接收方地址
    struct sockaddr_in addr_send;
    memset(&addr_send, 0, sizeof(addr_send));
    int len = sizeof(addr_send);

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        
        ssize_t size = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr *)&addr_send, &len);
        
        char *p = strchr(buf, '\n');
        if (p != NULL)  *p = '\0';

        if (strncmp(buf, "ok", 2) == 0) break;

        // 发送方端口, 从n网络字节序（大端）转h主机字节序（小端）
        int port = ntohs(addr_send.sin_port);
        // 发送方IP
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr_send.sin_addr, ip, INET_ADDRSTRLEN);

        printf("recv: %s,len = %ld,from:%s:%d\n", buf, size, ip, port);
    }

    close(fd);

    return 0;
}
