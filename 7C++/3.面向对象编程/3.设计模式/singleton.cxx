// singleton.cxx
// 单例模式
#include <iostream>

class Singleton
{
private:
    int x;
    int y;
    Singleton(int x) : x(x), y(x) {}  // 1.构造函数私有化
    Singleton() {}                    // 1.构造函数私有化
    
public:
    ~Singleton() {}

    // 2.开发一个静态接口
    // 饿汉式：调用之前提前初始化资源
    // 声明类变量
    static Singleton instance;

    static Singleton *getInstance(int x)
    {
        // 懒汉式：调用时初始化资源
        // 第一次调用才创建对象，分配空间
        // static Singleton instance(x);  // 类变量，只有一份
        return &instance;           // 每次调用都是返回同一份
    }

    void show()
    {
        std::cout << x << ", " << y << std::endl;
    }
};
// 初始化类变量
Singleton Singleton::instance;

int main(int argc, char const *argv[])
{
    Singleton *s1 = Singleton::getInstance(1);
    s1->show();

    return 0;
}
