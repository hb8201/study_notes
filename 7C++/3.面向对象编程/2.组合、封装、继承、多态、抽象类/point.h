// point.h
#include <iostream>
#include <string>

class Point
{
// 成员
private:
    // 属性
    int x;
    int y;

public:
    // 函数（方法）
    Point();
    Point(int x, int y);
    ~Point();
    void setx(int x);
    void sety(int y);
    int getx();
    int gety();
    void show();
};