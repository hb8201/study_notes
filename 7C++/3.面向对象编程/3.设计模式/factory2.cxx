// factory2.cxx
// 抽象工厂
#include <iostream>
#include <string>

// 产品抽象（父类）
class Phone
{
public:
    Phone() {}
    ~Phone() {}
    virtual void show() = 0;
};
class MiPhone : public Phone
{
public:
    MiPhone() {}
    ~MiPhone() {}
    void show() override
    {
        std::cout << "MiPhone\n";
    }
};
class IPhone : public Phone
{
public:
    IPhone() {}
    ~IPhone() {}
    void show() override
    {
        std::cout << "IPhone\n";
    }
};
// 产品抽象（父类）
class Pc
{
public:
    Pc() {}
    ~Pc() {}
    virtual void run() = 0;
};
class MacBook : public Pc
{
public:
    MacBook() {}
    ~MacBook() {}
    void run() override
    {
        std::cout << "MacBook\n";
    }
};
class RedMiPc : public Pc
{
public:
    RedMiPc() {}
    ~RedMiPc() {}
    void run() override
    {
        std::cout << "RedMiPc\n";
    }
};

// 工厂抽象
class Factory
{
public:
    Factory() {}
    ~Factory() {}

    virtual Phone *createPhone() = 0;
    virtual Pc *createPc() = 0;
};
class MiFactory : public Factory
{
public:
    MiFactory() {}
    ~MiFactory() {}
    Phone *createPhone() override
    {
        return new MiPhone;
    }
    Pc *createPc() override
    {
        return new RedMiPc;
    }
};
class AppleFactory : public Factory
{
public:
    AppleFactory() {}
    ~AppleFactory() {}
    Phone *createPhone() override
    {
        return new IPhone;
    }
    Pc *createPc() override
    {
        return new MacBook;
    }
};

int main(int argc, char const *argv[])
{
    Factory *factory;

    factory = new AppleFactory();
    // factory = new MiFactory();

    Phone *phone = factory->createPhone();
    Pc *pc = factory->createPc();

    phone->show();
    pc->run();

    return 0;
}
