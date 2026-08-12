// v.cxx
#include <iostream>
#include <string>
// 动态数组头文件，相当于封装好的自动扩容数组，不用手动 new/delete、不用自己写扩容函数
#include <vector>

int main(int argc, char const *argv[])
{
    // // 容器，模板类型
    // std::vector<int> v1;        // 0
    // std::vector<int> v2(10);    // 10个0
    // std::vector<int> v3(10, 1); // 10个1
    // std::vector<int> v4{10, 1}; // 10和1
    // std::vector<std::string> v5(10, "hello");

    // for (const auto &i : v5)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout <<  std::endl;

    // std::cout << v1.size() << std::endl;
    // std::cout << v2.size() << std::endl;
    // std::cout << v3.size() << std::endl;
    // std::cout << v4.size() << std::endl;

    // // 分配容量 17
    // v1.reserve(5);

    // for (int i = 0; i < 17; i++)
    // {
    //     // 在容器末尾添加 1
    //     v1.push_back(1);
    //     std::cout << v1.size() << "\t" << v1.capacity() << std::endl;
    // }

//----------------------------------------------------------------------

    // std::vector<int> v6 = {100, 200, 300, 400};
    // std::cout << v6.front() << ", " << v6.back() << std::endl;

    // // 返回指针数组的指针
    // int *p = v6.data();
    // p += 2;
    // std::cout << *p << std::endl;

    // v6[1] == 999;
    // std::cout << v6[1] << ", " << v6.at(2) << std::endl;

    // std::vector<int> v7 = v6;

    // for (auto &&i : v6)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

    // // 删除容器末尾的值
    // v6.pop_back();
    // for (auto &&i : v6)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

//--------------------------------------------

    std::vector<int> v8 = {100, 200, 300, 400};
    for (auto &&i : v8)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    // 获得一个迭代器（类似于指针）
    auto it = v8.begin();
    // it += 2;
    // 插入时需要迭代器
    v8.insert(it, 666);

    for (auto &&i : v8)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    // begin() 第一个元素位置
    // end() 最后一个元素后面
    for (auto i = v8.begin(); i != v8.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}
