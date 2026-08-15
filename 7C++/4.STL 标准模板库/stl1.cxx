// stl1.cxx
// 标准模版库
#include <iostream>

// 序列容器，线性表
#include <vector>       // 动态数组
#include <array>        // 固定数组
#include <list>         // 双向链表
#include <forward_list> // 单向链表
#include <deque>        // 双端队列（分块连续存储）

// 有序关联容器（红黑树）
// 1. 二叉搜索树
// 2. 根节点为黑色
// 3. 叶子节点的外部节点都为黑色
// 4. 红色节点不相邻
// 5. 任意分支节点的分支路径中，黑色节点数量相同
// 6. 插入的节点默认为红色
#include <set>          // 无重复值的集合
#include <map>          // 无重复值的键值对

// 无序关联容器（哈希表）
// 1. 通过“键（Key）”直接访问“值（Value）”的数据结构
// 2. 核心特点是查找、插入、删除的平均时间复杂度都为 O(1)（常数级）。
#include <unordered_set>//无序集合
#include <unordered_map>// 无序键值对

// 容器适配器
// 基于双端队列实现
#include <stack>        // 栈
#include <queue>        // 队列

int main(int argc, char const *argv[])
{

//                  vector
    // // 申请初始容量，且默认填充 0
    // std::vector<int> v1(4);

    // std::cout << v1.size() << ", " << v1.capacity() << std::endl;
    // std::cout << v1[0] << std::endl;
    
    // v1.push_back(1);
    // std::cout << v1.size() << ", " << v1.capacity() << std::endl;
    // std::cout << v1.at(4) << std::endl;

    // for (auto i : v1)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

//--------------------------------------------------

    // std::vector<int> v2;
    // // 申请初始容量，不做填充
    // v2.reserve(9);

    // v2.push_back(1000);

    // // 容器内空间构造对象，避免临时变量创建
    // v2.emplace_back(2000);

    // // 删除容器内最后一个元素
    // v2.pop_back();

    // for (auto i : v2)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

//---------------------------------------

    // std::vector<int> v3;
    // v3.reserve(9);

    // v3.emplace_back(2000);
    // v3.emplace_back(3000);
    // v3.emplace_back(4000);
    // v3.emplace_back(5000);

    // // 插入 要使用迭代器
    // // auto it = v3.begin();
    // // v3.insert(it, 333);

    // v3.insert(v3.begin(), 999);

    // // begin() 是容器的起始位置; end() 是容器的末尾 + 1 的位置
    // v3.insert(v3.end(), 888);

    // for (auto i : v3)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;
    
    // // 获取起始和末尾的元素
    // std::cout << v3.front() << ", " << v3.back() << std::endl;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//                      list
// std::list<int> l1;

// // 末尾插入
// l1.push_back(9);
// // 首端插入
// l1.push_front(1);

// // list 双向循环链表，不支持随机访问
// // l1[0];       
// // l1.at(0);

// // 指定位置插入
// l1.insert(l1.begin(), 100);

// for (auto i : l1)
// {
//     std::cout << i << ", ";
// }
// std::cout << std::endl;

//------------------------------------------------------------------
//------------------------------------------------------------------

//              deque
// // 双端队列，分块存储，块内连续存储，块索引指针存放在一个数组
// // 支持随机访问，性能比 vector 差
// // 支持双端插入，性能比 list 差
// std::deque<int> d;
// d.push_back(5);
// d.push_front(4);
// d.insert(d.begin() + 1, 7);

// std::cout << d.at(2) << std::endl;

// for (auto i : d)
// {
//     std::cout << i << ", ";
// }
// std::cout << std::endl;

//------------------------------------------------------------
//------------------------------------------------------------

//                    set（自动去重）与 multiset
// // std::set<int> s;
// std::multiset<int> s;
// s.insert(42);
// s.insert(32);
// s.insert(12);
// s.insert(76);
// s.insert(54);
// s.insert(98);
// s.insert(2);
// s.insert(2);
// s.insert(2);
// s.insert(33);
// s.insert(6);
// for (auto &&i : s)
// {
//     std::cout << i << ", ";
// }
// std::cout << std::endl;

//---------------------------------------------------------
//---------------------------------------------------------

//                             map（自动去重）与 multimap
// // key, value
// std::map<std::string, int> m1;
// m1["Python"] = 9;
// m1.insert({"C++", 43});
// m1.insert({"Rust", 12});
// m1.insert({"Tt", 33});
// m1.insert({"Tt", 53});

// std::cout << m1["C++"] << std::endl;

// for (auto &&i : m1)
// {
//     std::cout << i.first << ", " << i.second << std::endl;
// }
// std::cout << std::endl;

// std::multimap<std::string, int> m2;
// // m2["Python"] = 9;        // 不支持
// m2.insert({"Python", 9});
// m2.insert({"C++", 43});
// m2.insert({"Rust", 12});
// m2.insert({"Tt", 33});
// m2.insert({"Tt", 53});

// // std::cout << m2["C++"] << std::endl;     // 不支持

// for (auto &&i : m2)
// {
//     std::cout << i.first << ", " << i.second << std::endl;
// }

//------------------------------------
//------------------------------------

//                              unordered_set


//---------------------------------------------------------
//---------------------------------------------------------

//                              unordered_map


//-------------------------------------------------------------
//-------------------------------------------------------------

//                  stack
// std::stack<int> s;
// // 进栈
// s.push(1);
// s.push(2);
// s.push(3);
// s.push(4);
// s.push(5);
// s.push(6);

// // empty() 没有元素返回 true
// while (!s.empty())
// {
//     // 获取栈顶数据
//     std::cout << s.top() << ", ";
//     // 出栈
//     s.pop();
// }
// std::cout << std::endl;

//-------------------------------------------------------
//-------------------------------------------------------

//                         queue
// std::queue<int> q;
// q.push(1);
// q.push(2);
// q.push(3);
// q.push(4);
// q.push(5);
// q.push(6);

// while (!q.empty())
// {
//     std::cout << q.front() << ", ";
//     q.pop();
// }
// std::cout << std::endl;

//----------------------------------------------------
//----------------------------------------------------

//                      priority_queue
// std::priority_queue<int> q;
// q.push(2);
// q.push(76);
// q.push(34);
// q.push(23);
// q.push(16);
// q.push(8);
// q.push(56);
// q.push(83);

// while (!q.empty())
// {
//     std::cout << q.top() << ", ";
//     q.pop();
// }
// std::cout << std::endl;

return 0;
}
