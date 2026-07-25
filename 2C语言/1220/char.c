// char.c
// 字符
#include <stdio.h>

int main()
{
    // \ \转义字符
    // char ch[] = "中";   // 4

    // 字符数组
    char s1[] = {'a', 'b', 'c'};    // 3
    // 字符串 "" 括住文本内容， 空间大小是元素大小加一
    char s2[] = "abc";              // 4
    char s3[] = {'a', 'b', 'c', '\0'};      // s3 == s2
    char zi[] = "中国";     // 每个汉字3字节

    printf("%s ", s1);      // abcabc   因为是按照 %s (字符串)打印，而字符串打印的结束标志是 \0
    printf("%s ", s2);      // abc
    printf("%s ", s3);      // abc
    
    // char ch1 = '1';     // 字符 1
    // char ch2 = 1;       // 数值 1

    // printf("%d '%c'\n", ch1, ch1);
    // printf("%d '%c'\n", ch2, ch2);

    // for (int i = 0; i < 128; i++)               //'B' 66             'c' 99
    // {
    //     printf("'%c',(%3d)\t", i, i);
    //     if (i % 8 == 7)
    //     printf("\n");
    // }

    // char ch;
    // printf("输入一个字符：");
    // // scanf("%c", &ch);
    // // 从标准输入 stdin 读取一个字符
    // // getchar, getc
    // ch = getchar();
    // // ch = getc(stdin);

    // putchar(ch);
    // // putchar(ch, stdout);

    // if (ch >= '0' && ch <= '9')
    // {
    //     printf("是数字\n");
    // }

    // // 正则表达式（模式匹配）
    // if ((ch >= 97 && ch <= 'z') ||
    //     (ch >= 65 && ch <= 'Z'))
    // {
    //     printf("是字母\n");
    // }

    return 0;
}