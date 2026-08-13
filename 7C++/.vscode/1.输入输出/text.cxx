// text.cxx
/*
1. 定义命名空间 my
2. 基于 new/delete 实现动态数组 my::array
    - 结构体
    - 函数
*/
#include <iostream>
// 字符串操作
#include <cstring>

#define ARR_MAX 3

namespace my
{
    typedef struct
    {
        int MAX;
        int *arr;
        int len;
    } Array;

    void arr_init(Array *a)
    {
        a->MAX = ARR_MAX;
        a->arr = new int[a->MAX];
        a->len = 0;
    }

    void kr(Array *a)
    {
        a->MAX *= 2;
        int *arr = new int[a->MAX];
        memcpy(arr, a->arr, sizeof(int) * a->MAX);
        delete[] a->arr;
        a->arr = arr;
        arr = nullptr;
    }

    void arr_add(Array *a, int n)
    {
        if (a->len >= a->MAX * 0.8)
            kr(a);
        a->arr[a->len] = n;
        a->len++;
    }

    void arr_show(Array *a)
    {
        for (int i = 0; i < a->len; i++)
        {
            std::cout << a->arr[i] << std::endl;
        }
        std::cout << "len: " << a->len << ", MAX: " << a->MAX << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    my::Array a;
    my::arr_init(&a);
    my::arr_add(&a, 2);
    my::arr_add(&a, 3);
    my::arr_add(&a, 13);
    my::arr_add(&a, 23);
    my::arr_show(&a);

    return 0;
}
