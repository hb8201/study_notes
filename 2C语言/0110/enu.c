// enu.c
// enum
#include <stdio.h>
#include <string.h>

enum Sex
{
    MALE, FEMALE                    // 按顺序为01234，或者手动赋值 MALE = 10, FEMALE
};

int main()
{
    enum Sex sex = MALE;
    printf("%d\n", sex);
    return 0;
}