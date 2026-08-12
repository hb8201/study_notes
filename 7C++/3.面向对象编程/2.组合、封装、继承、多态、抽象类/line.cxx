// line.cxx
#include "line.h"

Line::Line(int startx, int starty, int endx, int endy)
    : start(*(new Point(startx, starty))), end(*( new Point(endx, endy)))
{
    std::cout << "Line(int startx, int starty, int endx, int endy) 构造函数\n";
}

Line::Line(Point &s, Point &e) : start(s), end(e)
{
    std::cout << "Line(Point &s, Point &e) 构造函数\n";
}

Line::~Line()
{
    std::cout << "~Line() 析构函数\n";
}

void Line::show()
{
    std::cout << "Line: start(" 
    << start.getx() << ", " << start.gety() << ") end(" 
    << end.getx() << ", " << end.gety() << ")\n";
}
