// mem.c
// 动态内存管理
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char tel1[12];       // 11
    char *tel2;          // 8
};

// 
char *cat(char *a, char *b)
{
    int size = strlen(a) + strlen(b) + 1;
    // char str[size];  错误 函数不能返回局部变量的地址
    char *str = (char *)malloc(size);  // 真确
    if (str)
    {
        strcpy(str, a);
        strcat(str, b);
    }
    return str;
}

int main()
{
    // struct User u1;
    // // u1.tel1 = "1234567891";  错误
    // strcpy(u1.tel1, "12345678911");
    // u1.tel2 = "15975345685";
    // u1.tel2 = malloc(12);        // 不填充，但效率高
    // memset(u1.tel2, 0, 12);

    // u1.tel2 = calloc(12);        // 全部填充为0，但效率低

    // printf("%s, %s\n", u1.tel1, u1.tel2);

    char *p = malloc(19);
    for (int i = 0; i < 19; i++)
    {
        printf("%d, %c\n", p[i], p[i]);
    }

    // char *p = cat("hello", "C++");
    // printf("%s, %p\n", p, p);
    // free(p);

    // // 数组大小确定
    // int a[6];       // 固定的

    // // 动态内存分配
    // int *p = (int *) malloc(sizeof(int) * 6);       // 24字节
    // if (p == NULL)
    // {
    //     // 
    //     perror("内存不足\n");
    //     return EXIT_FAILURE;
    // }
    // p[0] = 100;
    // p[1] = 200;
    // p[2] = 300;
    // p[3] = 400;
    // p[4] = 500;
    // p[5] = 600;

    // printf("before re: \t%p\n", p);
    // p = realloc(p, sizeof(int) * 7);
    // printf("after re: \t%p\n", p);

    // // 动态分配内存要手动释放
    // free(p);

    return 0;       // return EXIT_SUCCESS;
}