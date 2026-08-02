// server.c
// 对浏览器提供响应
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define QQMAX 20

typedef struct
{
    char ch[128];
}  Qingqiu;

int main(int argc, char const *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // 端口复用
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(fd, (struct sockaddr *)&addr, sizeof(addr));

    listen(fd, 9);
    printf("服务器启动!\n");

    while (1)
    {
        struct sockaddr_in c_addr;
        int len = sizeof(c_addr);
        int c_fd = accept(fd, (struct sockaddr *)&c_addr, &len);

        char buf[1024] = {0};
        recv(c_fd, buf, sizeof(buf), 0);
        printf("%s", buf);
        
        Qingqiu qq[QQMAX] = {0};
        int count = 0;

        // 获取方法
        char *ch1 = strchr(buf, ' ');
        strncpy(qq[count].ch, buf, ch1 - buf);
        printf("%s\n", qq[count].ch);
        count++;
        // 获取资源位置
        char *ch2 = strchr(ch1 + 1, ' ');
        strncpy(qq[count].ch, ch1 + 1, ch2 - ch1 - 1);
        printf("%s\n", qq[count].ch);
        count++;
        // 获取版本
        ch1 = strchr(buf, '\n');
        strncpy(qq[count].ch, ch2 + 1, ch1 - ch2 - 1);
        printf("%s\n", qq[count].ch);
        count++;

        char new_buf[1024];
        strncpy(new_buf, ch1 + 1, &buf[strlen(buf)] - ch1);
        // 获取首部字段
        while (1)
        {
            if (count >= QQMAX)
            {
                printf("首部字段过多，请扩大 QQMAX\n");
                return 1;
            }
            
        }

    }
    
    return 0;
}
