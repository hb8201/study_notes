// 结构体数组
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义常量，宏定义
#define NAME_SIZE 16

// 定义一个新的数据类型
typedef struct Student // typedef 为已有的数据类型定一个别名 struct Student -> Student
{
    char name[NAME_SIZE]; // 姓名（成员，字段）
    int age;              // 年龄
} Student;

int main()
{
    // Student s1;
    Student a[4] = {
        {"刘备", 21},
        {"关羽", 22},
        {.age = 23, .name = "张飞"},
    };
    strcpy(a[3].name, "诸葛亮"); // strncpy(a[3].name, "诸葛亮", NAME_SIZE - 1);
    a[3].age = 24;

    // 指针变量
    Student *p = a;
    for (int i = 0; i < 4; i++)
    {
        // printf("%s\t%d\n", a[i].name, a[i].age);     // 数组下标
        // printf("%s\t%d\n", (*p).name, (*p).age);     // 指针解引用
        printf("%s\t%d\n", p->name, p->age);            // 指针 ->
        p++;
    }

    return 0;
}