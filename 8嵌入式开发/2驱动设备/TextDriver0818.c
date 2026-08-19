// TextDriver0818.md
// 简单驱动设备
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

// 设备初始化：完成硬件设备初始化，并向操作系统注册该设备
static int test_init(void )
{
    // 设备硬件初始化

    // 设备注册

    // 输出的信息具有日志级别
    printk(KERN_ALERT"hello, my first driver login\n"); // 从内核中输出的函数
    return 0;
}

// 设备的注销：是否设备所占用的资源，从操作系统注销给该设备
static void text_exit(void)
{
    // 设备所占资源释放

    // 设备注销

    // 输出的信息具有日志级别
    printk(KERN_ALERT"bye, my first driver exit\n"); // 从内核中输出的函数
}

module_init(test_init);
module_exit(text_exit);


