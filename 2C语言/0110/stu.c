// stu.c
// struct
#include <stdio.h>
#include <string.h>

struct Date
{
    int year;
    int month;
    int day;
};

// 组合数据类型，封装了多个成员或者字段
struct Student
{
    char name[16];
    char sex;
    int score;
    struct Date birthday;   // 嵌套，但要注意两个结构体搭建的先后顺序，先搭建后嵌套
};

void prt(struct Student *s)
{
    printf("%s\t%c\t%d\t%4d/%02d/%02d\n", (*s).name, s->sex, (*s).score,
                s->birthday.year, s->birthday.month,s->birthday.day);
}

void update_score(struct Student *s, int score)
{
    // 形参获得了实参的一份拷贝
    // (*s).score = score;      解引用,和下面一行相同
    s->score = score;
}

int main()
{
    struct Student s1 = {"alice", 'F', 99, {2000, 7, 30}};
    struct Student s2 = {.score = 67, .sex = 'M', .name = "bob", .birthday = {2000, 1, 21}};
    struct Student s3;
    // s3.name = "rose";    错误
    strcpy(s3.name, "rose");
    s3.sex = 'M';
    s3.score = 78;
    s3.birthday.year = 2000;
    s3.birthday.month = 3;
    s3.birthday.day = 20;
    // \t table tab 重构
    prt(&s1);
    // s1.score = 100;
    update_score(&s1, 100);
    prt(&s1);
    prt(&s2);
    prt(&s3);

    printf("%ld\n",sizeof(s1));

    return 0;
}