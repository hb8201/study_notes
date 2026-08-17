// 订单
#include "dingd.h"

Dingd::Dingd() {}

Dingd::~Dingd() {}

void Dingd::adddingdx(std::shared_ptr<Dingdx> d)
{
    dingdxlist.push_back(d);
}

void Dingd::show()
{
    int cout = 0;
    std::cout << "订单列表" << std::endl;
    for (auto &&i : dingdxlist)
    {
        cout += i->showdingdx();
    }
    std::cout << "订单总价格: " << cout << std::endl;
}
