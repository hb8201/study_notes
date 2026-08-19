// a.c
// 测试程序
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    int n, len = 0;

    fd = open("/dev/Test_Char_Dev_0819", O_RDONLY);
    if (fd < 0)
    {
        perror("Open");
        exit(-1);
    }
    len = read(fd, &n, 4);
    printf("n = %d\n", n);
    return 0;
}

