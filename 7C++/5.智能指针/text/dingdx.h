// 订单项
#ifndef DINGDX_H
#define DINGDX_H
#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "chanp.h"

class Chanp;

class Dingdx
{
public:
    std::map<std::shared_ptr<Chanp>, int> dingdanx;

    Dingdx(std::shared_ptr<Chanp> p, int n);
    ~Dingdx();
    int showdingdx();
};

#endif