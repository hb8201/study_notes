// oop.cxx
// 继承
#include <iostream>

// A, B, C, D
class A
{
private:
    int pri_a; // 私有的，类的内部使用

protected:
    int pro_a; // 受保护的，类的内部与子类使用

public:
    int pub_a; // 共有的，都可以使用
    A() : pri_a(0), pro_a(0), pub_a(0)
    {
        std::cout << "A()" << std::endl;
    }
    A(int a, int b, int c) : pri_a(a), pro_a(b), pub_a(c)
    {
        std::cout << "A(int a, int b, int c)" << std::endl;
    }
    // virtual 虚函数
    virtual ~A()
    {
        std::cout << "~A()" << std::endl;
    }
    virtual void show()
    {
        std::cout << "A: " << pri_a << ", " << pro_a << ", " << pub_a << std::endl;
    }
    int getpri_a()
    {
        return pri_a;
    }
};

// B 继承了 A   class B : public A {}
class B : public A
{
private:
    int pri_b;

public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    B(int a, int b, int c, int d) : A(a, b, c), pri_b(d)
    {
        std::cout << "B(int a, int b, int c, int d)" << std::endl;
    }
    virtual ~B()
    {
        std::cout << "~B()" << std::endl;
    }
    // 子类中与父类同名的函数：方法重写（覆盖）
    // override，语法检查，判断 show() 是否是父类中的虚函数
    virtual void show() override
    {
        std::cout << "B: " << getpri_a() << ", " << pro_a << ", " 
        << pub_a << ", " << pri_b << std::endl;
    }
};

class C : public B
{
private:

public:
    C()
    {
        pub_a = 2;
        std::cout << "C()" << std::endl;
    }
    ~C()
    {
        std::cout << "~C()" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // A a;
    // A b(1, 2, 3);
    // a.show();
    // b.show();

//----------------------------

    // B b(1, 2, 3, 4);
    // b.show();

//-------------------------------

    // A *a;
    // a = new A();
    // a->show();
    // delete a;

    // B *b;
    // b = new B();
    // b->show();
    // delete b;

//---------------------------------

    // 用 父类型指针 去操作 子类型对象
    A *a;
    a = new B();
    a->show();      // 加上 virtual 后，调用和对象类型一致的函数
    delete a;

    return 0;
}
