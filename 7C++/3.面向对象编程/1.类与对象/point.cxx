// point.cxx
#include "point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int x)
{
    this->x = x;
    y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    std::cout << "构造函数\n";
}

void Point::show()
{
    std::cout << "x：" << x << "，y：" << y << std::endl;
}
