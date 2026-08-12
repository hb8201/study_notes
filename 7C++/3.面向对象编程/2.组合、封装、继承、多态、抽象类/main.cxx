// main.cxx
#include "line.h"

int main(int argc, char const *argv[])
{
    // Point p1;
    // Point p2(3, 4);
    // p1.show();
    // p1.setx(2);
    // p1.show();
    // p2.show();

//------------------------------------

    // Line l1;
    // l1.show();

    Point p1;
    Point p2(2, 4);
    Line l2(p1, p2);
    l2.show();
    p1.setx(1);
    p1.show();
    l2.show();

    // Line l3(1, 3, 5, 7);
    // l3.show();

    
    return 0;
}
