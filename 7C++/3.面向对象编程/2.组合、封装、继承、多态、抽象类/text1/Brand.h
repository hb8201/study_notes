// Brand.h
#ifndef BRAND_H
#define BRAND_H

#include <iostream>
#include <string>
#include <vector>

class Product;

class Brand
{
public:
    std::string name;
    std::vector<Product *> productlist;   // 品牌销毁，产品销毁（聚合关系）

    Brand(std::string n);
    ~Brand();
    void show();
    void addproduct(Product *p);
};

#endif