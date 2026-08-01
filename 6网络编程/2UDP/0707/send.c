// send.c
// 发送方
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

    // MAX MTU = 1500 - 28
    char msg[1500 - 28];

    // 设置接收方地址
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "122.51.21.94", &addr.sin_addr);
    addr.sin_port = htons(9527);

    while (1)
    {
        memset(&msg, 0, sizeof(msg));
        printf(":");
        fgets(msg, 1500 - 28, stdin);

        // 发送
        ssize_t len = sendto(fd, msg, sizeof(msg), 0, (struct sockaddr *)&addr, sizeof(addr));
        
        if (strncmp(msg, "ok", 2) == 0)  break;
    }

    close(fd);

    return 0;
}
