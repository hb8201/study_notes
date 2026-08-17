// 订单
#ifndef DINGD_H
#define DINGD_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "dingdx.h"

class Dingd
{
public:
    std::vector<std::shared_ptr<Dingdx>> dingdxlist;

    Dingd();
    ~Dingd();
    void adddingdx(std::shared_ptr<Dingdx> d);
    void show();
};

#endif