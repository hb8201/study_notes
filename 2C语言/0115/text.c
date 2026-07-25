#include <stdio.h>

void fib()
{
    int n;
    printf("求斐波那契数列第n个数：");
    scanf("%d", &n);
    int f[n];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    printf("%d\n", f[n - 1]);
}

void days()
{
    int year, month, day;
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("请输入年月日（xxxx-xx-xx）：");
    scanf("%d-%d-%d", &year, &month, &day);
    int d = day;

    for (int i = 1; i <= month; i++)
    {
        d += m[i];
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        d += 1;

    printf("%d-%d-%d 是第 %d 天\n", year, month, day, d);
}

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

int diff(Date *d1, Date *d2)
{
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days1 = d1->day;
    for (int i = 1555; i < d1->year; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            days1 += m[j];
        }
        if ((d1->year % 4 == 0 && d1->year % 100 != 0) || (d1->year % 400 == 0))
            days1 += 1;
    }
    for (int i = 1; i <= d1->month; i++)
    {
        days1 += m[i];
    }
    if ((d1->year % 4 == 0 && d1->year % 100 != 0) || (d1->year % 400 == 0))
        days1 += 1;

    int days2 = d2->day;
    for (int i = 1555; i < d2->year; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            days2 += m[j];
        }
        if ((d2->year % 4 == 0 && d2->year % 100 != 0) || (d2->year % 400 == 0))
            days2 += 1;
    }
    for (int i = 1; i <= d2->month; i++)
    {
        days2 += m[i];
    }
    if ((d2->year % 4 == 0 && d2->year % 100 != 0) || (d2->year % 400 == 0))
        days2 += 1;
    
    int d = days1 - days2;
    if (d < 0)
        d = -d;
    return d;
}

int main()
{
    fib();
    days();

    Date *d1, *d2;
    printf("请输入第一个日期年份大于1555（xxxx-xx-xx）：");
    scanf("%d-%d-%d", &d1->year, &d1->month, &d1->day);
    printf("请输入第二个日期年份大于1555（xxxx-xx-xx）：");
    scanf("%d-%d-%d", &d2->year, &d2->month, &d2->day);
    int x = diff(d1, d2);
    printf("相差%d天\n", x);
    return 0;
}