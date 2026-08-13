// op.cxx
// 静态属性
#include <iostream>

class User
{
public:
    // 静态属性（类属性），是属于 User 这个类的，而不是 User 的对象
    static int count;
    // 成员属性,堆空间的每个对象
    int id;

    User() 
    {
        id = ++count;
    }
    ~User() {}
    void sayhello()
    {
        std::cout << "我是 " << id << ", 共计 " << count << std::endl;
    }
    // 静态函数只能访问静态属性，无法访问其他属性
    static void setcount(int n)
    {
        count = n;
    }
};
// 初始化类属性
int User::count = 0;

int main(int argc, char const *argv[])
{
    User u1;
    User u2;
    User::setcount(1000);
    User u3;
    u1.sayhello();
    u2.sayhello();
    u3.sayhello();

    return 0;
}
