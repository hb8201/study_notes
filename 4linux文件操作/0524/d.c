// d.c
// 遍历目录

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void getType(int d)
{
    switch (d)
        {
        case 4: printf("d\n");
            break;
        case 8: printf("-\n");
            break;
        case 10: printf("l\n");
            break;
        default: printf("x\n");
            break;
        }
}

int main()
{
    DIR *dir = opendir("/home/hb/牛耳/8.linux文件操作/0524");
    if (dir == NULL)
    {
        perror("无法打开目录\n");
        return 1;
    }
    printf("OK\n");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        // 字符串比较 相等为0
        if (strncmp(entry->d_name, ".", 1))
        {
            printf("%ld\t%s\t%d\t",entry->d_ino, entry->d_name, entry->d_type);
            getType(entry->d_type);
        }

        // .
        // ..
        if (entry->d_type == 4)
        {
            // 递归
        }
        else
        {
            // 其他文件
        }
    }
    //
    closedir(dir);

    return 0;
}
