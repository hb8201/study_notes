// 产品
#ifndef CHANP_H
#define CHANP_H
#include <iostream>
#include <string>
#include <memory>

#include "pinp.h"

class Pinp;

class Chanp
{
public:
    std::string name;
    int price;
    Pinp *pinp;
    // std::weak_ptr<Pinp> pinp;

    Chanp(std::string n, int p, Pinp * P);
    ~Chanp();

    void showchanp();
    void showpinp();
};



#endif