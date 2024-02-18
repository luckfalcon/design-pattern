#pragma once
#include <string>
/*
代理者(代理追求者)和被代理者(追求者)具有相同的公共方法接口
在追求者中实现方法接口的具体内容，在代理者中调用追求者的方法
*/
class SchoolGirl
{
public:
    SchoolGirl(const std::string &name) : girl_name(name) {}
    std::string GetName() { return girl_name; }

private:
    std::string girl_name;
};

class GiveGit
{
public:
    GiveGit() {}
    virtual ~GiveGit() {}

protected:
    virtual void GiveDolls() = 0;
    virtual void GiveFlower() = 0;
    virtual void GiveChocolate() = 0;
};
class Pursuit : public GiveGit
{
public:
    Pursuit(SchoolGirl *mm) : mm(mm) {}
    ~Pursuit(){
        if (mm != nullptr)
            delete mm;
    }
    void GiveDolls() override;
    void GiveFlower() override;
    void GiveChocolate() override;

private:
    SchoolGirl *mm;
};
class proxy : public GiveGit
{
public:
    proxy(SchoolGirl *mm) : gg(new Pursuit(mm)) {}
    ~proxy(){
        if (gg != nullptr)
            delete gg;
    }
    void GiveDolls() override;
    void GiveFlower() override;
    void GiveChocolate() override;

private:
    Pursuit *gg;
};
void test_proxy();