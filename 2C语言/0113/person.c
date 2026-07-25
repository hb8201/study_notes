// person.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

typedef struct Person
{
    char name[16];        // 姓名
    int age;              // 年龄
    Date birthday;        // 生日
    struct Person *lover; // 配偶 指针
} Person;

int main()
{
    Person p2 = {"bob"};
    Person p1 = {"allice", 21, {2004, 1, 23}, &p2};
    // p1.lover = &p2;

    printf("%s\t%d\t%d-%d-%d\t%s\n", p1.name, p1.age,
           p1.birthday.year,
           p1.birthday.month,
           p1.birthday.day,
           p1.lover->name
        );
    return 0;
}