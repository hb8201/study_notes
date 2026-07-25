// str.c
#include <stdio.h>
// strlen, strcpy， strcat, strcmp
#include <string.h>

int main()
{
    char s1[] = "hello";
    // s1 = "bye";      错误
    s1[0] = 'B';
    printf("%s\n", s1);

    char *s2 = "hello";
    s2 = "bye";
    // s2[0] = 'B';     错误
    printf("%s\n", s2);

    // // 字符数组
    // char s1[] = {'h', 'e', 'l', 'l', 'o'};
    // // 字符串数组
    // char s2[] = {'h', 'e', '\0', 'l', 'o', '\0'};
    // char s3[] = "hello";    // 字符长度 n, 空间大小为 n + 1
    // char *s4 = "hello";
    // // %s
    // printf("s1 = %s, 空间 = %ld, 字符串长度 = %ld\n", s1, sizeof(s1), strlen(s1));
    // printf("s2 = %s, 空间 = %ld, 字符串长度 = %ld\n", s2, sizeof(s2), strlen(s2));
    // printf("s3 = %s, 空间 = %ld, 字符串长度 = %ld\n", s3, sizeof(s3), strlen(s3));
    // printf("s4 = %s, 空间 = %ld, 字符串长度 = %ld\n", s4, sizeof(s4), strlen(s4));
    return 0;
}