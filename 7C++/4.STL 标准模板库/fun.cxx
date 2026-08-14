// fun.cxx
// Lambda 表达式：匿名函数
#include <iostream>
#include <vector>
#include <algorithm>    // 大量算法

int main(int argc, char const *argv[])
{
    // // [] 不访问外部变量
    // auto f1 = []()
    // {
    //     std::cout << "hello\n";
    // };
    // f1();

//--------------------------------------------

    // // [=]  只读，不能修改
    // int n = 9;
    // auto f2 = [=]()
    // {
    //     std::cout << n << std::endl;
    // };
    // f2();

//--------------------------------------------

    // // [&]  可以修改
    // int n = 9;
    // auto f3 = [&]()
    // {
    //     n++;
    //     std::cout << n << std::endl;
    // };
    // f3();

//---------------------------------

    // // 可传入参数，并且可以指定返回类型
    // auto f = [](int a, int b) -> int { return a + b;};

    // std::cout << f(2, 4) << std::endl;

//---------------------------------------------------

//                    排序 sort(1.起始, 2.末尾, 3.排序规则) 

    // std::vector<int> v = {12, 85, 41, 32, 71, 52};
    // // std::sort(v.begin(), v.end());   // 排序规则不写,默认从小到大
    // std::sort(v.begin(), v.end(), [](int x, int y){return x > y;});
    // for (auto &&i : v)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

//--------------------------------------------------------------

//                遍历一个范围内的所有元素 for_each(1.起始, 2.末尾, 3.具体操作)

    // std::vector<int> v = {12, 85, 41, 32, 71, 52};
    // std::for_each(v.begin(), v.end(), [](int e){std::cout << e << ", ";});
    // std::cout << std::endl;

//--------------------------------------------------------------

//                  find_if(1.起始, 2.末尾, 3.过滤条件)

    // std::vector<int> v = {12, 85, 41, 32, 71, 52};
    // // 过滤,返回一个迭代器
    // auto it = std::find_if(v.begin(), v.end(), [](int x){ return x > 50;});
    // while (it != v.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }

//-------------------------------------------------------------------



    return 0;
}
