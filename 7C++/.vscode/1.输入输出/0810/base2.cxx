// base2.cxx
// 引用与指针
# include <iostream>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void swap2(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main(int argc, char const *argv[])
{
    int a = 42;
    int b = 64;

    // 指针 *
    int *p;     // 野指针
    p = &a;     // 赋值     p -> a
    *p = 43;    // 解引用
    p = &b;     // 再次赋值  p -> b
    
    // 引用 & 标识 r 是引用，变量的别名
    // 声明时必须赋值，不能再次更改绑定对象，只能修改值,且 a 与 r 的值是相同的
    int &r = a;
    std:: cout << &a << ", " << &r << std::endl;
    std:: cout << a << ", " << r << std::endl;

    // 交换 a 与 b 的值
    swap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap2(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
