/*
    燃油、电力（新能源）
    - 车：油车、电车、混合
    - 摩托：油车、电车
    
*/
#include <iostream>
#include <string>

// 加油
class Gas
{
public:
    virtual ~Gas() = default;
    virtual void refurl() = 0;
};
// 充电
class Electrie
{
public:
    virtual ~Electrie() = default;
    virtual void charge() = 0;
};

class Car
{
private:
    
public:
    Car(/* args */) {}
    ~Car() {}
};

class Moto
{
private:
   
public:
    Moto(/* args */) {}
    ~Moto() {}
};

class GasCar : public Car, public Gas
{
private:
   
public:
    GasCar(/* args */) {}
    ~GasCar() {}
};

class ElectrieCar : public Car, public Electrie
{
private:
  
public:
    ElectrieCar(/* args */) {}
    ~ElectrieCar() {}
};


class GasMoto : public Moto, public Gas
{
private:

public:
    GasMoto(/* args */) {}
    ~GasMoto() {}
};