// IO.c
// 系统调用

// POSIX std 技术规范
#include <unistd.h>
#include <stdio.h>
// File Control Operations
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    // 打开文件，获得文件描述符
    // 0644     0 110 100 100
    int fd = open("xyz.txt", O_CREAT | O_WRONLY, 0644);
    printf("%d\n", fd);
    char buf[] = "hello POSIX!";
    int n = write(fd, buf, sizeof(buf));
    printf("%d\n", n);
    close(fd);

    // 0 stdin
    // 1 stdout
    // 2 stderr
    // 3 新打开的

    // char buf[16] = "hello POSIX";
    // if (write(1, buf, 16) != 16)
    // {
    //     write(2, "error", 6);
    // }

    // char buf[16] = {0};
    // // memset
    // int n = read(0, buf, sizeof(buf) - 1);
    // write(1, buf, n);


    return 0;
}
