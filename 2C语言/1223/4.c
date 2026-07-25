#include <stdio.h>
#include "my.h"

int main()
{
    int a[26] = {0}, b[26] = {0};

    read_word(a);
    read_word(b);
    equal_array(a, b);

    return 0;
}