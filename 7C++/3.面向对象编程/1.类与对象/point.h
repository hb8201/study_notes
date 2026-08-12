// poiht.h
#include <iostream>
#include <string>

class Point
{
private:
    int x;
    int y;
    
public:
    Point();
    Point(int x);
    Point(int x, int y);
    ~Point();
    void show();
};


