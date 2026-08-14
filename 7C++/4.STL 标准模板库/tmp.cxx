// tmp.cxx
// 泛型 模板编程
// - 函数模板
// - 类模板
#include <iostream>
#include <string>

// 函数模板
template <typename T>
T t_max(T a, T b)
{
    return a > b ? a : b;
}
// 函数模板
template <typename T>
void swap(T &a, T &b)
{
    T t = a;
    // auto t = a;
    a = b;
    b = t;
}

// 类模板
template <typename T>
class Box
{
private:
    T data;

public:
    Box(T val) : data(val) {}
    
    T get();
    void set(T val);
    void show()
    {
        std::cout << data << std::endl;
    }
};
template <typename T>
T Box<T>::get()
{
    return data;
}
template <typename T>
void Box<T>::set(T val)
{
    data = val;
}

int main(int argc, char const *argv[])
{
    // std::cout << t_max<int>(1.2, 3.2) << std::endl;
    // std::cout << t_max(1.2, 3.2) << std::endl;

//---------------------------------------------------------

    // int a = 4;
    // int b = 6;
    // std::string c = "hello";
    // std::string d = "你好";

    // swap(a, b);
    // swap(c, d);
    // std::cout << a << ", " << b << std::endl;
    // std::cout << c << ", " << d << std::endl;

//------------------------------------------------------------

    Box box1(45);
    Box box2(45.56);
    Box<std::string> box3("sdfgds");

    box1.set(44);
    box2.set(47.5);
    box3.set("hello");

    box1.show();
    box2.show();
    box3.show();

    return 0;
}

