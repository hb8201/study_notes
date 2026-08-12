// op3.cxx
// 接口类
#include <iostream>

// 特殊的抽象类
class USB
{
public:
    virtual ~USB() {};
    virtual void plug() = 0;
    virtual void run() = 0;
    virtual void pull() = 0;
};

class Player
{
public:
   virtual ~Player() {};
   virtual void start() = 0;
   virtual void pause() = 0;
   virtual void stop() = 0;
};

// 多继承
class MPS : public USB, public Player
{
private:

public:
    MPS() 
    {
        std::cout << "MPS()" << std::endl;
    }
    ~MPS() 
    {
        std::cout << "~MPS()" << std::endl;
    }
    void plug() override
    {
        std::cout << "plug()" << std::endl;
    }
    void run() override
    {
    std::cout << "run()" << std::endl;
    }
    void pull() override
    {
    std::cout << "pull()" << std::endl;
    }
    void start() {}
    void pause() {}
    void stop() {}
    void play()
    {
        plug();
        run();
        pull();
    }
};

int main(int argc, char const *argv[])
{
    // USB *u1 = new MPS();
    // u1->plug();
    // u1->run();
    // u1->pull();
    // delete u1;

    MPS *m1 = new MPS();
    m1->play();
    delete m1;

    return 0;
}
