// io1.c
// 字符读取
#include <stdio.h>
int main()
{
// 文件名：绝对路径 /home/hb/a.txt、相对路径 a.txt, ../a.txt
// 操作模式：r（读）, w（先清空再写）, a（只在末尾写）, r+（读写）, w+（先清空再读写）, rb（二进制）, wb（二进制）
FILE *fp = fopen("abc.txt", "r");
if (fp == NULL)
{
perror("无法打开文件\n");
return 1;
}
printf("成功打开文件\n");
// 读取
int ch;
// EOF -1 End Of File
while ((ch = fgetc(fp)) != EOF)
{
printf("%c", ch);
}
// 关闭
fclose(fp);
return 0;
}
