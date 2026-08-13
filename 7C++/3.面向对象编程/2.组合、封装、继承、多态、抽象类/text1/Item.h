// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Product;

class Item
{

public:
    std::string productname;
    int price;
    int num;

    Item(std::string n, int p, int num);
    ~Item();
    void show();
};

#endif
