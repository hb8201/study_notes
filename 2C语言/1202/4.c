#include <stdio.h>

int main()
{
    int a;
    printf("请输入风速（海里/小时）：");
    scanf("%d", &a);
    if (a < 1)
        printf("Calm（无风）\n");
    else if (a < 3)
        printf("Light air（轻风）\n");
    else if (a < 27)
        printf("Breeze（微风）\n");
    else if (a < 47)
        printf("Gale（大风）\n");
    else if (a < 63)
        printf("Storm（暴风）\n");
    else
        printf("Hurricane（飓风）\n");
    return 0;
}