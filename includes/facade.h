#pragma once

class SubSystemA
{
public:
    void methodCall();
    void methodRelease();
};

class SubSystemB
{
public:
    void methodSet();
    void methodUnset();
};

class SubSystemC
{
public:
    void methodInstall();
    void methodUnstall();
};
//关联关系,含有对象的引用
class Facade//外观类,隐藏子系统的实现细节
{
public:
    Facade() : sbsA(new SubSystemA()), sbsB(new SubSystemB()), sbsC(new SubSystemC()) {}
    ~Facade();
    void facdeMethodA();
    void facdeMethodB();

private:
    SubSystemA *sbsA;
    SubSystemB *sbsB;
    SubSystemC *sbsC;
};

// client
void test_facade();