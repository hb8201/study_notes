// str.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // strtok token 字符串拆分
    char s1[] = "alice, bob, tom, jack, rose";
    char s2[sizeof(s1)];
    strcpy(s2, s1);
    // 1.目标字符串    2.分隔符
    char *token = strtok(s2, ", ");
    while (token != NULL)
    {
        printf("%s\n", token);
        // 1.参数NULL
        token = strtok(NULL, ", ");
    }
    printf("over: %s\n", s1);
    printf("over: %s\n", s2);

    // strstr 字符串查找
    // char s1[] = "hello";

    // // BF, KMP
    // char *p = strstr(s1, "el");
    // if (p == NULL)
    // {
    //     printf("没有找到\n");
    // }
    // else
    // {
    //     printf("index = %ld\n", p - s1);
    //     printf("%s\n", p);
    // }

    // strcmp
    // char s2[] = "javac";
    // char s1[] = "javaa";
    // // ASCII
    // int r = strncmp(s1, s2, 4);
    // printf("%d\n", r);
    
    // strchr 字符查找
    // char s1[] = "javaa";
    // char *p = strchr(s1, 'a');
    // if (p != NULL)
    // {
    //     printf("%ld\n", p - s1);
    //     printf("%s\n", p);
    // }

    // strcat, strcpy, strlen
    // char s1[] = "hello";
    // char s2[] = "C++";

    // int len = strlen(s1) + strlen(s2) + 1;
    // char s3[len];

    // // strcat
    // // strcat(s3, s1);
    // // strcat(s3, s2);
    // strcpy(s3, s1);         // 覆盖
    // strncat(s3, s2, 3);     // 追加、拼接

    // printf("%s\n", s3);

    // strncpy(s1, "welcome", strlen(s1));
    // printf("%s\n", s1);
    
    return 0;
}

