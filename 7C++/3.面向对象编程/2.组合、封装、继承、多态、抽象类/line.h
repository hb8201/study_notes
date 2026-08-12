// line.h
#include "point.h"

class Line
{
private:
    // 线由两个点组合而成

    // 数据拷贝，修改点的坐标，对应线的值不会改变   ❌
    // Point start;
    // Point end;

    // 数据引用，但不能使用默认构造函数
    Point &start;
    Point &end;

    // Point *start;
    // Point *end;

public:
    Line();
    Line(int startx, int starty, int endx, int endy);
    Line(Point &s, Point &e);
    ~Line();
    void show();
};


