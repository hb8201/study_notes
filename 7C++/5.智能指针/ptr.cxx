// ptr.cxx
// 智能指针
#include <iostream>
#include <string>
#include <memory>

class Person
{
public:
    std::string name;

    Person(std::string n) : name(n)
    {
        std::cout << "Person(std::string name)" << std::endl;
    }
    ~Person()
    {
        std::cout << "~Person()" << std::endl;
    }
};

void x(std::shared_ptr<Person> p)
{
    std::cout << "x: " << p->name << std::endl;
    std::cout << "x count: " << p.use_count() << std::endl;
}
void y(std::shared_ptr<Person> p)
{
    std::cout << "y: " << p->name << std::endl;
    std::cout << "x count: " << p.use_count() << std::endl;
}
int main(int argc, char const *argv[])
{
//                     裸指针
    // Person *p1 = new Person("alice");
    // std::cout << p1->name << std::endl;
    // // 要手动 delete
    // delete p1;

//---------------------------------------------------------

//                    独占指针
    //auto p = std::make_unique<Person>("alice")
    // // std::unique_ptr<Person> p1(new Person("alice"));

    // std::cout << p1->name << std::endl;

    // // 独占指针不能赋值（拷贝），智能 std::move 移动，移动之后，p1为空
    // std::unique_ptr<Person> p2 = std::move(p1);
    // if (p1 == nullptr)
    // {
    //     std::cout << "nullptr" << std::endl;
    // }

    // // 获得了对应的裸指针，裸指针不要手动析构
    // Person *p3 = p2.get();
    // std::cout << p3->name << std::endl;
    // std::cout << p2->name << std::endl;
    
    // // 释放所有权，交给裸指针，p2就不能再使用了，且裸指针要手动析构
    // Person *p4 = p2.release();
    // std::cout << p4->name << std::endl;
    // delete p4;

    // // 重置，销毁资源，如果已经被销毁了，就不会执行
    // p2.reset();

    // // 交换
    // std::unique_ptr<Person> p5(new Person("jack"));
    // std::unique_ptr<Person> p6(new Person("tom"));
    // swap(p5, p6);
    // std::cout << p5->name << std::endl;
    // std::cout << p6->name << std::endl;

//---------------------------------------------------------------

//                  共享指针
    // std::shared_ptr<Person> p1(new Person("alice"));
    // auto p1 = std::make_shared<Person>("alice");
    // std::cout << p1.use_count() << std::endl;
    
    // auto p2 = p1;
    // auto p3 = p1;
    // std::cout << p1.use_count() << std::endl;
    
    // p2.reset();     // count--
    // std::cout << p1.use_count() << std::endl;
    
    // x(p1);  // count = 3
    // y(p1);  // count = 3
    // std::cout << p1.use_count() << std::endl;

//--------------------------------------------------------

//                弱指针

//              ptr2.cxx


    return 0;
}
