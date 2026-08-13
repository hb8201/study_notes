// Order.cxx
// 订单

#include "Order.h"
#include "Item.h"

Order::Order()
{
}

Order::~Order()
{
}

void Order::addItem(Item item)
{
    itemlist.push_back(item);
}
void Order::addItem(std::string productname, int price, int num)
{
    // // 先创建临时对象Item，然后传过去，再创建相应对象
    // itemlist.push_back(Item(productname, price, num));
    
    // 传过去之后，再创建相应对象，避免了临时对象创建，只拷贝与销毁
    itemlist.emplace_back(productname, price, num);
}
void Order::show()
{
    std::cout << customer.name << std::endl;
}