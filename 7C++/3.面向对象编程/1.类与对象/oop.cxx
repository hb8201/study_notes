// oop.cxx
#include <iostream>
#include <string>

// ~ 访问修饰符；私有的、公有的、受保护的
class Cat
{
    // 封装：保护内部状态及实现的细节，访问修饰符
    // 1. 成员变量加上私有的访问修饰符，通过调用共有函数去 读取/修改 私有成员
private:
    std::string name;
    int age;
public:
    int getage()
    {
        return age;
    }
    void setage(int n)
    {
        // 参数有效性检查
        if (n > 0 && n < 20)
        {
            age = n;
        }
    }
    std::string getname()
    {
        return name;
    }
    // 构造函数：初始化对象的成员
    Cat() {
        name = "喵喵";
        age = 1;
        std::cout << "Cat() 构造函数\n";
    }
    // C++ 中允许存在 同名不同参 的函数（函数重载）
    Cat(std::string s) {
        name = s;
        age = 1;
        std::cout << "Cat() 构造函数\n";
    }
    // 析构函数：销毁对象的成员
    ~Cat() {
        std::cout << "~Cat() 析构函数\n";
    }
};

int main(int argc, char const *argv[])
{
    // 创建了对象
    // c1 为函数内的局部变量，栈空间，函数结束时，自动销毁
    Cat c1("嘻嘻");
    c1.setage(11);
    std::cout << c1.getage() << "\n";
    std::cout << c1.getname() << "\n";

    // 创建堆空间对象
    Cat *c2 = new Cat();
    std::cout << c2->getage() << "\n";
    std::cout << c2->getname() << "\n";
    delete c2;
    c2 = nullptr;

    return 0;
}
