// 与a进行收发
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct 
{
    int fd;
    struct sockaddr_in addr_a;
    struct sockaddr_in addr_b;
} ADDR;

void *send_b(void *add)
{
    while (1)
    {
        ADDR addr = *((ADDR *)add);
        char msg[1500-28];
        memset(msg, 0, sizeof(msg));
        fgets(msg, sizeof(msg), stdin);
    
        sendto(addr.fd, msg, sizeof(msg), 0, (struct sockaddr *)&addr.addr_a, sizeof(addr.addr_a));
        if (strncmp(msg, "ok", 2) == 0) break;
    }
}
void *recv_b(void *add)
{
    while (1)
    {
        ADDR addr = *((ADDR *)add);
        char buf[1500-28];
        memset(buf, 0, sizeof(buf));
        int len = sizeof(buf);

        recvfrom(addr.fd, buf, sizeof(buf), 0, (struct sockaddr *)&addr.addr_a, &len);
        if (strncmp(buf, "ok", 2) == 0) break;
        printf("收到：%s\n", buf);
    }
}

int main(int argc, char const *argv[])
{
    ADDR addr;
    // 套接字
    addr.fd = socket(AF_INET, SOCK_DGRAM, 0);

    // 地址复用
    int opt = 1;
    setsockopt(addr.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 设置b的地址
    memset(&addr.addr_b, 0, sizeof(addr.addr_b));
    addr.addr_b.sin_family = AF_INET;
    addr.addr_b.sin_port = htons(9500);
    addr.addr_b.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(addr.fd, (struct sockaddr *)&addr.addr_b, sizeof(addr.addr_b));

    // 获取a的地址
    memset(&addr.addr_a, 0, sizeof(addr.addr_a));
    addr.addr_a.sin_family = AF_INET;
    addr.addr_a.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &addr.addr_a.sin_addr);

    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, send_b, &addr);
    pthread_create(&t2, NULL, recv_b, &addr);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(addr.fd);

    return 0;
}