// 实现一个客户端多次读写（循环加退出条件）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(fd,(struct sockaddr *)&addr, sizeof(addr));

    listen(fd, 9);
    printf("服务器准备就绪\n");

    while (1)
    {
        printf("等待连接...\n");

        struct sockaddr_in c_addr;
        memset(&c_addr, 0, sizeof(c_addr));
        int len = sizeof(c_addr);

        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &len);
        while (1)
        {

            char buf[1024];
            memset(buf, 0, 1024);
            int size = read(c_fd, buf, 1024);
            printf("收到：%s", buf);
            if (strcmp(buf, "ok\r\n") == 0)
                break;

            char msg[] = "TCP Server!\n";
            write(c_fd, msg, sizeof(msg));
                
        }
        close(c_fd);
    }
    close(fd);

    return 0;
}
