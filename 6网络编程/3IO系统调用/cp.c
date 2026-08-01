// cp.c
// 拷贝文件
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        perror("参数不足\n");
        return 1;
    }
    int fd_in;
    int fd_out;
    // 源
    fd_in = open(argv[1], O_RDONLY);
    // 目标
    fd_out = open(argv[2], O_CREAT | O_WRONLY, 0660);
    
    // 通过文件描述符获得文件信息
    struct stat s;
    fstat(fd_in, &s);
    printf("%ld/%ld\n", s.st_size, s.st_blksize);



    // char ch;
    char buf[32] = {0};
    int n;
    while ((n = read(fd_in, buf, sizeof(buf))) > 0)
    {
        write(fd_out, buf, n);
    }

    printf("ok\n");
    close(fd_in);
    close(fd_out);

    return 0;
}
