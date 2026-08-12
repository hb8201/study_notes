// op2.cxx
// 纯虚函数
#include <iostream>
#include <string>

// 抽象类：包含纯虚函数的类称为抽象类，不能创建对象，但可以用于继承（子类要 重写 这个纯虚函数）
// 抽象类中至少包含一个纯虚函数，可以有具体函数
class Shape
{
private:

protected:
    std::string name;
    
public:
    Shape() : name("图形")
    {
        std::cout << "Shape()" << std::endl;
    }
    // 虚函数
    virtual ~Shape() 
    {
        std::cout << "~Shape()" << std::endl;
    }
    // 纯虚函数
    virtual double area() = 0;
    // 具体函数
    void show()
    {
        std::cout << "图形的名称：" << name << std::endl;
    }
};

class Circle : public Shape
{
private:
    
public:
    Circle()
    {
        name = "圆形";
        std::cout << "Circle()" << std::endl;
    }
    ~Circle() 
    {
        std::cout << "~Circle()" << std::endl;
    }
    // 子类要 重写 这个纯虚函数，否则编译报错
    double area() override
    {
        return 0;
    }
};
class Trignle : public Shape
{
private:
    
public:
    Trignle() 
    {
        name = "三角形";
        std::cout << "Trignle()" << std::endl;
    }
    ~Trignle() 
    {
        std::cout << "~Trignle()" << std::endl;
    }
    double area() override
    {
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Shape *s;

    s = new Circle();
    s->show();
    delete s;

    s = new Trignle();
    s->show();
    delete s;

    return 0;
}
