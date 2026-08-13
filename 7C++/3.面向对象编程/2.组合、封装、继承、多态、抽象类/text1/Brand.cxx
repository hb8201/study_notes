// Brand.cxx
// 品牌
#include "Brand.h"
#include "Product.h"

Brand::Brand(std::string n) : name(n) {}

Brand::~Brand() {}

void Brand::show()
{
    std::cout << "品牌：" << name << std::endl;
    std::cout << "------------------" << std::endl;
    for (auto i : productlist)
    {
        std::cout << i->name << ", " << i->price << std::endl;
    }
    std::cout << "------------------" << std::endl << std::endl;
}

void Brand::addproduct(Product *p)
{
    productlist.push_back(p);
}
