// iob2.c
// 读二进制文件
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
    FILE *fp = fopen("a.data", "rb");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    // int *p1;
    // struct person *p2;
    // fread(p1, sizeof(int), 1, fp);
    // fread(p2, sizeof(struct person), 1, fp);
    // printf("%d\n", *p1);
    // printf("%s, %d\n", p2->name, p2->age);

    struct person p[3];
    fread(p, sizeof(struct person), 3, fp);
    for (int i = 0; i < 3; i++)
    {
        printf("%s, %d\n", p[i].name, p[i].age);
    }
    fclose(fp);

    return 0;
}