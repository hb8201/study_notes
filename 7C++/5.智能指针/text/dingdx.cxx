// 订单项
#include "dingdx.h"

Dingdx::Dingdx(std::shared_ptr<Chanp> p, int n)
{
    dingdanx.insert({p, n});
}

Dingdx::~Dingdx() {}

int Dingdx::showdingdx()
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "订单项: ";
    std::cout << "产品: " << dingdanx.begin()->first->name
            << ", 单价: " << dingdanx.begin()->first->price 
            
            << ", 数量: " << dingdanx.begin()->second
            << ", 订单项总价: " << dingdanx.begin()->first->price * dingdanx.begin()->second << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    return dingdanx.begin()->first->price * dingdanx.begin()->second;
}
