// p.cxx
#include "point.h"

int main(int argc, char const *argv[])
{
    Point p1;
    Point p2(2);
    Point p3(4, 8);

    p1.show();
    p2.show();
    p3.show();

    return 0;
}
