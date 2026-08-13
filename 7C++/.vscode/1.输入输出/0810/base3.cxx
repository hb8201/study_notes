// base3.cxx
// 自定义类型与动态内存管理
#include <iostream>

// 命名空间
namespace xyz
{
    int n{9};   // 列表初始化

    void hello()
    {
        std::cout << "Hello xyz\n";
    }
}
// 命名空间如果重名，并且内容都不同，那么会自动合并
// 命名空间允许嵌套使用
namespace xyz
{
    int m{12};
    namespace abc
    {
        void abc()
        {
            std::cout << "Hello abc\n";
        }
    }
}

// 定义一个类型 id 为无符号长整型
// C
typedef unsigned long int id;
// C++
using id = unsigned long int;



// 调用命名空间
using namespace xyz;
// 调用命名空间中的某个函数
using  xyz::hello;
// 调用之后就不需要 xyz::

int main(int argc, char const *argv[])
{
    std::cout << "n: " << xyz::n << std::endl;
    xyz::hello();
    xyz::abc::abc();


    // 动态分配空间
    // C
    int *p = (int *)malloc(sizeof(int));
    *p = 42;
    free(p);    // 释放空间，地址不变，值没了
    p = NULL;

    // C++
    // int *p1 = new int(42);
    int *p1 = new int;
    *p1 = 42;
    delete p1;  // 释放空间，地址不变，值没了
    p1 = nullptr;


    return 0;
}
