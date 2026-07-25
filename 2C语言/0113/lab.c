#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pingp
{
    char name[20];
    int year;
    int shul;
} Pingp;

typedef struct Chanp
{
    char name[20];
    Pingp *pp;
} Chanp;

int main()
{
    Pingp p1 = {"品牌1", 1999, 3};
    Pingp p2 = {"品牌2", 2005, 1};

    Chanp c1 = {"产品1", &p1};
    Chanp c2 = {"产品2", &p1};
    Chanp c3 = {"产品3", &p1};
    Chanp c4 = {"产品4", &p2};

    printf("%s\t%d\t%d\n", p1.name, p1.year, p1.shul);
    printf("%s\t%d\t%d\n", p2.name, p2.year, p2.shul);
    printf("%s\t%s\n", c1.name, c1.pp->name);
    printf("%s\t%s\n", c2.name, c2.pp->name);
    printf("%s\t%s\n", c3.name, c3.pp->name);
    printf("%s\t%s\n", c4.name, c4.pp->name);
    return 0;
}