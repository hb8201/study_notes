#include <stdio.h>
#include "my.h"

int main()
{
    char ch[10][10];

    generate_random_walk(ch);
    print_array(ch);

    return 0;
}