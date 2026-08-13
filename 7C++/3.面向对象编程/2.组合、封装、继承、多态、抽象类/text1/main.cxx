/*
    1. 定义以下类
    - 品牌
        - id
        - 名称
        - 商品 （动态数组）
    - 商品
        - id
        - 名称
        - 价格
        - 品牌
    - 客户
    - 地址
    - 订单      
    - 订单项     
*/
#include "Brand.h"
#include "Product.h"
#include "Order.h"
#include "Item.h"
#include "Customer.h"

int main(int argc, char const *argv[])
{
    Brand b1("Mi");
    Brand b2("Apple");

    Product p1("Red Mi", &b1, 999);
    Product p2("SU 7", &b1, 111999);
    Product p3("IPad", &b2, 992229);
    
    b1.addproduct(&p1);
    b1.addproduct(&p2);
    b2.addproduct(&p3);

    b1.show();
    b2.show();

    Order o1;
    // Item item1(p1.name, p1.price, 2);
    // o1.addItem(item1);
    o1.addItem(Item(p1.name, p1.price, 2));
    o1.addItem(p2.name, p2.price, 9);

    
    return 0;

}
