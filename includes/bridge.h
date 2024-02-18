#pragma once
class Implementor // 抽象类
{
public:
    virtual void operationImp() = 0;
};
class ConcreteImplementorA : public Implementor
{
public:
    void operationImp() override;
};
class ConcreteImplementorB : public Implementor
{
public:
    void operationImp() override;
};
class Abstraction
{
public:
    virtual ~Abstraction() {}; // 抽象类，必须定义，否则在继承调用时会发生错误
    virtual void operation() = 0;
    virtual void SetImp(Implementor *imp) = 0;

protected:
    Implementor *imp;
};
class RedefineAbstraction : public Abstraction
{
public:
    void SetImp(Implementor *imp) override;
    void operation() override;
    ~RedefineAbstraction(){
        if(this->imp!=nullptr)
            delete imp;
    }
};
void test_bridge();