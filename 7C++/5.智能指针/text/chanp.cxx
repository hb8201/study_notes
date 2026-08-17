// 产品
#include "chanp.h"

Chanp::Chanp(std::string n, int p, Pinp *P) : name(n), price(p), pinp(P) {}

Chanp::~Chanp() {}

void Chanp::showchanp()
{
    std::cout << "产品: " << name << ", 单价: " << price << std::endl;
}

void Chanp::showpinp()
{
    std::cout << "所属品牌: " << pinp->getpinp() << std::endl;
}

