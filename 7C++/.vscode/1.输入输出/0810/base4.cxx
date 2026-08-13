// base4.cc
// 数组动态分配空间
#include <iostream>
// #include <string.h>
#include <cstring>

int main(int argc, char const *argv[])
{
    // C
    // int *p = malloc(sizeof(int) * 3);
    // free(p);

    // C++
    // int *p = new int[3];
    // p[0] = 100;
    // p[1] = 200;
    // p[2] = 300;
    int *p = new int[3] {100, 200, 300};

    for (int i = 0; i < 3; i++)
    {
        std::cout << p[i] << std::endl;
    }
    
    
    // 扩容
    int *new_p = new int[6];
    memcpy(new_p, p, sizeof(int) * 3);

    delete[] p;
    p = nullptr;

    new_p[3] = 400;
    new_p[4] = 500;
    new_p[5] = 600;
    for (int i = 0; i < 6; i++)
    {
        std::cout << new_p[i] << std::endl;
    }
    delete[] new_p;
    new_p = nullptr;

    return 0;
}
