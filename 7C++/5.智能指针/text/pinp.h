// 品牌
#ifndef PINP_H
#define PINP_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "chanp.h"

class Chanp;

class Pinp
{
private:
    std::string name;

    // std::vector<Chanp *> chanplist;
    std::vector<std::shared_ptr<Chanp>> chanplist;

public:
    Pinp();
    Pinp(std::string n);
    ~Pinp();

    std::string getpinp();
    void showpinp();
    void addchanp(std::shared_ptr<Chanp> c);
    void showchanp();
    void show();
};



#endif
