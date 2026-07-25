// loop
#include <stdio.h>


int main()
{
    // for
    // for (int i = 0; i < 9; i++)
    // {
    //     printf("Hello %d\n", i);
    // }
    
    // int i = 0;
    // for (;;)
    // {
    //     printf("%d", i);
    //     i++;
    //     if(i > 9) break;
    // }

    // break, continue
    for (int i = 1; i <= 9; i++)
    {
        if(i == 4) continue;    // 结束整个循环
        if(i == 7) break;       // 跳过本次循环体中后续的代码，进入下次循环
        printf("%d,", i);
    }
    
    // do-while

    // char ch;
    // do
    // {
    //     printf("...\n");
    //     printf("输入 Y 继续，输入 N 退出：");
    //     // 接收一个字符，输入一个字符+回车
    //     scanf("%c", &ch);   // ch = getchar();
    //     getchar();
    // } while (ch == 'Y' || ch == 'y');

    // printf("the end\n");
    
    // int n, m = 0;
    // printf("输入一个整数：");
    // scanf("%d", &n);
    
    // while (n > 0)
    // {
    //     m += n % 10;
    //     n /= 10;
    // }

    // printf("%d\n", m);

    return 0;
}