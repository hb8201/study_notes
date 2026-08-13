// op4.cxx
// 多继承中大的棱形继承，采用虚继承
// 论中间层（如 X 和 Y）被继承多少次，最终的派生类（如 Z）中只会保留一份虚基类
#include <iostream>

class A
{
public:
    int n;

    A() {}
    A(int n) : n(n) {}
    ~A() {}
    void show()
    {
        std::cout << n << std::endl;
    }
};
// 虚继承
class X : virtual public A
{
public:
    X() : A(1) {}
    X(int n) : A(n) {}
    ~X() {}
};
// 虚继承
class Y : virtual public A
{
public:
    Y() : A(2) {}
    Y(int n) : A(n) {}
    ~Y() {}
};

class Z : public X, public Y
{
public:
    Z() {}
    ~Z() {}
};

int main(int argc, char const *argv[])
{
    Z z;
    z.X::show();
    z.Y::show();

    return 0;
}
