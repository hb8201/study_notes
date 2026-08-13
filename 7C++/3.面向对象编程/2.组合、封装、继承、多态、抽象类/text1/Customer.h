// Customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

class Order;

class Customer
{

public: 
    std::vector<Order *> orderlist;
    std::string name;

    Customer(/* args */);
    ~Customer();
};

#endif
