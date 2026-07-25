// sprintf.c
// 格式化输出到字符串

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // format printf to flie
    // fprintf()
    FILE *fp = fopen("a.csv", "w");
    // 格式化输出到文件
    fprintf(fp, "%s, %d\n", "alice", 19);
    fprintf(fp, "%s, %d\n", "bob", 20);
    fprintf(fp, "%s, %d\n", "jack", 21);
    fprintf(stdout, "%s, %d\n", "tom", 22);
    fclose(fp);

    // // format printf to string
    // // sprintf()
    // char text[64];
    // char *name = "bob";
    // char *tel = "1234523";
    // int age = 23;
    // // 简化字符串拼接过程
    // sprintf(text, "姓名：%s， 手机号：%s， 年龄：%d", name, tel, age);
    // printf("%s\n", text);

    return 0;
}