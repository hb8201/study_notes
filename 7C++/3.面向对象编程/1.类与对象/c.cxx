// c.cxx
#include "cat.h"

int main(int argc, char const *argv[])
{
    Cat c1;
    Cat c2("哈哈");
    Cat c3("嘻嘻哈哈", 6);

    c1.show();
    c2.show();
    c3.show();
    
    return 0;
}
