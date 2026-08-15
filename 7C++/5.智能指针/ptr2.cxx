// ptr2.cxx
// 弱指针
#include <iostream>
#include <string>
#include <memory>

struct Node
{
    int val;
    std::weak_ptr<Node> next;   // 弱指针是特殊的共享指针,计数器不会累加

    Node(int v) : val(v) 
    {
        std::cout << "Node()" << std::endl;
    }
    ~Node()
    {
        std::cout << "~Node()" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // RAII
    auto n1 = std::make_shared<Node>(5);        // C++14
    std::shared_ptr<Node> n2(new Node(9));      // C++11

    n1->next = n2;
    n2->next = n1;
    std::cout << n1.use_count() << std::endl;
    std::cout << n2.use_count() << std::endl;
    
    std::weak_ptr<Node> n3 = n1;
    std::cout << n1.use_count() << std::endl;

    // 弱指针不能解引用,但可以通过 lock() 临时返回共享指针
    std::cout << n3.lock()->val << std::endl;

    return 0;
}
