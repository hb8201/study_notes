// cat.h
#include <iostream>
#include <string>

class Cat
{
private:
    std::string name;
    int age;

public:
    Cat();
    Cat(std::string name);
    Cat(std::string name, int n);
    ~Cat();

    std::string getname();
    int getage();
    void setage(int n);

    void show();
};


