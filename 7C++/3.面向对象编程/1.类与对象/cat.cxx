// cat.cxx
#include "cat.h"

Cat::Cat()
{
    std::cout << "构造函数\n";
    name = "嘻嘻";
    age = 1;
}

Cat::Cat(std::string name)
{
    std::cout << "构造函数\n";
    age = 1;

    // name = name;     ❌

    // 成员变量与参数重名
    this->name = name;

    /*
        或者
        通过 列表初始化 将 s 赋给 name
        Cat::Cat(std::string s):name(s) {}
    */
}

Cat::Cat(std::string name, int n)
{
    this->name = name;
    if (n > 0 && n < 30)
        age = n;
}

Cat::~Cat()
{
    std::cout << "析构函数\n";
}

std::string Cat::getname()
{
    return name;
}

int Cat::getage()
{
    return age;
}

void Cat::setage(int n)
{
    if (n > 0 && n < 30)
        age = n;
}

void Cat::show()
{
    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
}
