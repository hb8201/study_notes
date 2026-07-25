#include <stdio.h>
int main()
{
    int i=6;
    double j=6.66;
    printf("%d,%f,%d\n",i,j);
    printf("hello world\n");
    return 0;
}




//file查看文件信息

//编译 gcc hello.c -o hello    ->hello
//执行 ./hello

//汇编 gcc -S hello.c    ->hello.s
//编译 gcc -c hello.s    ->hello.o
//链接 gcc hello.o -o hello    ->hello
//执行 ./hello
