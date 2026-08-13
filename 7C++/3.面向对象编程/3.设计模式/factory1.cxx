// factory1.cxx
// 工厂模式（静态工厂）
#include <iostream>
#include <string>

enum DocType
{
    WORD, PPT
};

// 产品抽象（父类）
class Doc
{
protected:
    std::string name;

public:
    Doc(std::string name) : name(name) {}
    ~Doc() {}

    void open()
    {
        std::cout << "OPEN: " << name << std::endl;
    }
    virtual void edit() = 0;
};

class Word : public Doc
{
public:
    Word() : Doc("未命名") {}
    Word(std::string name) : Doc(name) {}
    ~Word() {}

    void edit() override
    {
        std::cout << "EDIT Word: " << name << std::endl;
    }
};

class Ppt : public Doc
{
public:
    Ppt() : Doc("未命名") {}
    Ppt(std::string name) : Doc(name) {}
    ~Ppt() {}

    void edit() override
    {
        std::cout << "EDIT Ppt: " << name << std::endl;
    }
};

// 工厂
class Wps
{
public:
    Wps() {}
    ~Wps() {}
    
    static Doc *create(DocType type, std::string name)
    {
        Doc *doc;
        switch (type)
        {
            case WORD:
                doc = new Word(name);
                break;
            case PPT:
                doc = new Ppt(name);
                break;
            default:
                break;
        }
        return doc;
    }
};

int main(int argc, char const *argv[])
{
    Doc *d;

    d = Wps::create(WORD, "简历");
    d->open();
    d->edit();

    d = Wps::create(PPT, "答辩");
    d->open();
    d->edit();
    
    return 0;
}
