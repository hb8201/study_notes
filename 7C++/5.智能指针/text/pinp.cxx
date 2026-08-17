// 品牌
#include "pinp.h"

Pinp::Pinp() : name("未命名") {}

Pinp::Pinp(std::string n) : name(n) {}

Pinp::~Pinp() {}

std::string Pinp::getpinp()
{
    return name;
}

void Pinp::showpinp()
{
    std::cout << "------------------------" << std::endl;
    std::cout << "品牌: " << name << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Pinp::addchanp(std::shared_ptr<Chanp> c)
{
    chanplist.push_back(c);
}

void Pinp::showchanp()
{
    std::cout << "------------------------" << std::endl;
    std::cout << "产品列表" << std::endl;
    for (auto &&i : chanplist)
    {
        std::cout << "产品: " << i->name << ", 单价: " << i->price << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void Pinp::show()
{
    showpinp();
    showchanp();
}
