#include "pinp.h"
#include "chanp.h"
#include "dingdx.h"
#include "dingd.h"

int main(int argc, char const *argv[])
{
    Pinp p1("牢大");
    auto c1 = std::make_shared<Chanp>("冰红茶", 30, &p1);
    auto c2 = std::make_shared<Chanp>("man", 105, &p1);
    auto c3 = std::make_shared<Chanp>("坠机", 55, &p1);

    p1.addchanp(c1);
    p1.addchanp(c2);
    p1.addchanp(c3);
    p1.show();

    Dingd d1;
    auto dx1 = std::make_shared<Dingdx>(c1, 15);
    auto dx2 = std::make_shared<Dingdx>(c2, 2);
    auto dx3 = std::make_shared<Dingdx>(c3, 8);

    d1.adddingdx(dx1);
    d1.adddingdx(dx2);
    d1.adddingdx(dx3);
    d1.show();




    
    return 0;
}
