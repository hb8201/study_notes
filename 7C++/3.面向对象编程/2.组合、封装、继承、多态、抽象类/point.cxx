// point.cxx
#include "point.h"

Point::Point()
{
    x = 0;
    y = 0;
    std::cout << "Point() 构造函数\n";
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    std::cout << "Point(int x, int y) 构造函数\n";
}
Point::~Point()
{
    std::cout << "~Point() 析构函数\n";
}
void Point::setx(int x)
{
    this->x = x;
}
void Point::sety(int y)
{
    this->y = y;
}
int Point::getx()
{
    return x;
}
int Point::gety()
{
    return y;
}
void Point::show()
{
    std::cout << "Point: {x = " << x << ", y = " << y << "}\n";
}