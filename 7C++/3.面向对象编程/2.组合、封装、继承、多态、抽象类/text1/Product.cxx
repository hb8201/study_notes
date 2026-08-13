// Product.cxx
// 产品
#include "Brand.h"
#include "Product.h"

// 产品

Product::Product(std::string n, Brand *b, int p) : name(n), brand(b), price(p) {}

Product::~Product() {}

void Product::show()
{
    std::cout << "产品：" << name << "，价格：" << price << "，品牌：" << brand->name << std::endl;
}