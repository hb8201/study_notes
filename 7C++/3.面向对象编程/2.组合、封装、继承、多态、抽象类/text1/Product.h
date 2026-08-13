// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Brand;

// 产品
class Product
{
public:
    std::string name;
    int price;
    Brand *brand;       // 产品销毁，品牌不能销毁（关联关系）

    Product(std::string n, Brand *b, int p);
    ~Product();
    void show();
};

#endif