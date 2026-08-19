#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/uaccess.h>

// cat /proc/devices        没有占用的设备号
#define MAJOR_NUM 238

// 定义一个模拟设备信息的数据
static int dev_value = 99;  // 内核空间的数据

// 声明许可协议
MODULE_LICENSE("GPL");

// 定义具体的IO实现：读写
// read(fd, buf, len)
static ssize_t test_char_read (struct file *fp, char __user *buf, size_t len, loff_t *t)
{
    // 将内核空间中 dev_value 的值写入到 用户空间
    int length = copy_to_user(buf, &dev_value, 4);

    return sizeof(dev_value);
}

static ssize_t test_char_write (struct file *fp, const char __user *buf, size_t len, loff_t *t)
{
    int length = copy_from_user(&dev_value, buf, 4);
    return sizeof(dev_value);
}

// 定义一个设备的IO接口     设备和设备文件对应操作的关联
static struct file_operations myfops =
{
    .owner =  THIS_MODULE,
    .read = test_char_read,   // 系统调用read的时候，具体的write
    .write = test_char_write,
};

// 初始化函数
static int __init myinit(void)
{
    // 完成设备初始化：设备硬件初始化和数据初始化

    // 向操作系统注册
    if (register_chrdev(MAJOR_NUM, "Test_Char_Dev_0819", &myfops))
    {
        // 注册失败
        printk("<4>Register Failed\n");
        return -1;
    }
    else
    {
        // 注册成功
        printk("<4>Register Success\n");
        return 0;
    }
    return 0;
}

// 释放函数
static void __exit myexit(void)
{
    printk("<4>Test_Char_Dev_0819 exit");
    unregister_chrdev(MAJOR_NUM, "Test_Char_Dev_0819");
}

module_init(myinit);
module_exit(myexit);
