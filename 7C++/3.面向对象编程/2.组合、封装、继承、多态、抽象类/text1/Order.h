// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Item.h"

class Order
{

public:
    Customer customer;
    std::vector <Item> itemlist;    // 组合

    Order();
    ~Order();
    void addItem(Item item);
    void addItem(std::string productname, int price, int num);
    void show();
};

#endif