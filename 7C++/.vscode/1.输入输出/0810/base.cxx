// base.cxx
// cxx
// Input Stream/Output Stream 输入输出流：字节的序列
#include <iostream>
// cout、cin
// 命名空间 std::
// using namespace std;
// g++ base.xx -o base

int main(int argc, char const *argv[])
{
    // // cout << "hello\n";
    // std::cout << "hello\n";

    // int a;
    // int b;
    // std::cin >> a >> b;
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "a + b = " << a + b << std::endl;

    // int val = 0;
    // int sum = 0;
    // while (std::cin >> val)
    // {
    //     sum += val;
    // }
    // std::cout << "sum = " << sum << std::endl;

    int a = 1;      // C
    int b = {1};    // 列表初始化（推荐）
    int c(1);       // 构造函数初始化
    int d{1};       // 列表初始化（推荐）

    double n = {8.9};
    int v1 = n;
    int v2 = {n};   // 窄化类型
    int v3{n};      // 窄化类型
    auto v4 = n;    // 编译器根据右边的值，自动推导变量的类型
    std::cout << v1 << v2 << v3 << v4 << std::endl;

    return 0;
}


