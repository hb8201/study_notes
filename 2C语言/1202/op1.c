#include <stdio.h>

int main()
{
    // ------------------闰年
    // 1) 被4整除,且不能被100整除
    // 2) 被400整除
    int year;
    printf("输入年份：");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d是闰年\n", year);
    }
    else
    {
        printf("%d不是闰年\n", year);
    }

    // -----------------------------
    // int s;
    // printf("输入成绩： ");
    // scanf("%d", &s);
    // //      s >= 90     A
    // // 90 > s >= 80     B
    // // 80 > s >= 70     C
    // // 70 > s >= 60     D
    // //      s  < 80     E
    // char g;
    // if (s >= 90)
    // {
    //     g = 'A';
    // }
    // else if (s >= 80)
    // {
    //     g = 'B';
    // }
    // else if (s >= 70)
    // {
    //     g = 'C';
    // }
    // else if (s >= 60)
    // {
    //     g = 'D';
    // }
    // else
    // {
    //     g = 'E';
    // }
    // printf("分数是: %d,等级: %c\n", s, g);

    // int a = 1;
    // int b = 2;
    // // &&, || 短路
    // if (a > b && b++ > 2)       // if (a < b || b++ > 2)
    // {

    // }
    // printf("%d\n", b);      // b = 2

    // int age;
    // printf("输入年龄: ");
    // scanf("%d", &age);

    // if (age >= 18 && age < 70)
    // {
    //     printf("有效年龄\n");
    // }
    // else
    // {
    //     printf("无有效年龄\n");
    // }

    return 0;
}