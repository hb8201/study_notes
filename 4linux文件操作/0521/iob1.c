// iob1.c
// 文件： text file, binary file   二进制文件写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char name[19];
    int age;
};

int main()
{
    // 结构体数组
    struct person list[3] = {
        {"alice", 19},
        {"bob", 20},
        {"jack", 21}
    };
    // 结构体定义方法1
    struct person p1 = {"alice", 22};
    // 方法2
    struct person p2;
    p2.age = 34;
    strcpy(p2.name, "jack");
    // 方法3
    struct person *p3 = malloc(sizeof(struct person));
    p3->age = 24;
    strcpy(p3->name, "tom");

    // mod: rb, wb, ab
    FILE *fp = fopen("a.data", "wb");
    if (fp == NULL)
    {
        perror("文件无法打开\n");
        return 1;
    }
    // 写
    // int n = 23;
    // fwrite(&n, sizeof(int), 1, fp);
    // fwrite(&p1, sizeof(struct person), 1, fp);
    fwrite(list, sizeof(struct person), 3, fp);
    // 关闭
    fclose(fp);

    return 0;
}
