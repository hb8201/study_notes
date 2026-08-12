// str.cxx
// 字符串对象操作
#include <iostream>
// 字符串对象
#include <string>

int main(int argc, char const *argv[])
{
    // std::string s1;             // 默认为空字符串
    // std::string s2 = "hello";   // 字面量拷贝
    // std::string s3("hello");    // 构造函数初始化
    // std::string s4(6, 'a');     // 初始化了6个a

    // // std::cin >> s1;     // 读到空格或换行结束
    // while (1)
    // {
    //     getline(std::cin, s1); // 读到换行结束
    //     if (s1.empty())
    //         break;
    //     auto len = s1.size();   // auto 类型自动推导
    //     std::cout << "'" << s1 << "'" << std::endl;
    //     std::cout << "len = " << len << std::endl;
    // }

    // std::cout << s2 << std::endl;
    // std::cout << s3 << std::endl;
    // std::cout << s4 << std::endl;

    // // 字符串对象拼接，字符串对象+字符串对象，字符串对象+字面量，字面量+字面量（不行）,
    // // 拼接时至少要有一个字符串对象
    // std::string s5 = s3 + "2026" + s4;
    // s5 += " !";
    // s5.append(" !");
    // std::cout << s5 << std::endl;

//----------------------------------------------------------------------

    // // 字符串比较
    // std::string s6 = "hello";
    // if (s6 == "hello")
    // {
    //     std::cout << "相同\n";
    // }

    // // 字符串遍历
    // for (int i = 0; i < s6.size(); i++)
    // {
    //     // s6[] 不做越界判断
    //     // s6.at() 会做越界判断，更安全
    //     std::cout << s6[i] << "\t" << s6.at(i) << std::endl;
    // }

//------------------------------------------------------------------------

    // // 从 s7 获取一个元素拷贝给 r   无法修改s7的值
    // std::string s7 = "hello";
    // for(auto r : s7)
    // {
    //     std::cout << r << std::endl;
    //     r++;
    // }
    // std::cout << s7 << std::endl;

    // // const auto &r 只读引用，性能比 auto r 好
    // for(const auto &r : s7)
    // {
    //     std::cout << r << std::endl;
    // }
    // std::cout << s7 << std::endl;

    // // 从 s7 获取一个元素起别名 r   可以修改s7的值
    // for (auto &r : s7)
    // {
    //     std::cout << r << std::endl;
    //     r++;
    // }
    // std::cout << s7 << std::endl;

//--------------------------------------------------

    // 字符串对象插入
    std::string s8 = "hello";
    s8.insert(2, " 2026 ");
    std::cout << s8 << std::endl;

    // 字符串对象删除
    s8.clear();
    std::cout << s8 << std::endl;
    std::cout << s8.size() << std::endl;    // 大小为0
    std::cout << s8.capacity() << std::endl;    // 容量不变

    // 字符串对象替换
    std::string s9 = "hello";
    s9.replace(1, 2, "ss");
    std::cout << s9 << std::endl;


    return 0;
}
