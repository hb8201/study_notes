#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *name_2(char *n)
{
    char *name = n;
    int a = strlen(name);
    char b[3];
    sprint(b, "%s%s\n", name[a-2], name[a-1]);
    return b;
}
int main(int argc, char const *argv[])
{
    printf("%s", name_2("ajfad.c"));
    return 0;
}
