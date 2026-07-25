// 动态分配
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
    // 动态（长度可变）数组
    Student *ptr = (Student *)malloc(4 * sizeof(Student));
    if (ptr == NULL)
    {
        printf("空间分配失败\n");
        return EXIT_FAILURE;
    }
    // 
    for (int i = 0; i < 4; i++)
    {
        // printf("请输入姓名与年龄：");
        // scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);

        // 字符串：学生0001，学生0001，学生0003，学生0004
        char str[16];
        sprintf(str, "学生%04d", i + 1);
        // 字段赋值
        strcpy((ptr + i)->name, str);
        (ptr + i)->age = 20 + i;
        // strcpy(ptr[i].name, str);
        // pyr[i].age = 20 + i;
        // 打印
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%s\t%d\n", (ptr + i)->name, (ptr + i)->age);
    }

    return EXIT_SUCCESS;
}