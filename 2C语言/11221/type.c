//type.c
//基本类型

/**
 * type.c
 * 
 * @author   hb@qq.com
 * @date   2025/11/22
 */
#include <stdio.h>

 int main()
 {
    // printf()参数一：字符串模板
    //sizeof()获得类型或者变量在内存中占用的空间大小，单位字节
    //复制：shift + alt + 下 向下复制光标内容
    //撤销：ctrl + z
    //多行编辑：ctrl + alt + 下   esc退出
    //% 占位符，%d 格式化输出 int，%ld 格式化输出 long int
    printf("大小：%ld\n",sizeof(char));             //1
    printf("大小：%ld\n",sizeof(short));            //2
    printf("大小：%ld\n",sizeof(int));              //4
    printf("大小：%ld\n",sizeof(long));             //8
    printf("大小：%ld\n",sizeof(long long));        //8
    printf("大小：%ld\n",sizeof(float));            //4
    printf("大小：%ld\n",sizeof(double));           //8
    printf("大小：%ld\n",sizeof(long double));      //16
    printf("大小：%ld\n",sizeof(_Bool));            //1

    return 0;
 }

