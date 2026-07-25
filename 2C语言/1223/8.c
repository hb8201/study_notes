#include <stdio.h>
#include "my.h"

int main()
{
    // srand((unsigned)time(NULL)); // 用当前时间戳设定时间种子
    int x = 0, y = 0;
    while (1)
    {
        srand((unsigned)time(NULL)); // 用当前时间戳设定时间种子
        char a;
        int b;
        b = play_game();

        if (b)
            x++;
        else
            y++;

        printf("Play again? ");
        scanf(" %c", &a);   // 注意：输入字符后按回车， \n 会留在输入缓冲区，下次scanf会直接读取
        printf("\n");       // 但在 %c 前面加个空格就可以解决

        if (a != 'y' && a != 'Y')
            break;
    }

    printf("Wins: %d    Losses: %d\n", x, y);

    return 0;
}