#pragma once
#include"templatemethod.h"

class TemplateMethod
{
public:
    TemplateMethod() {}
    virtual ~TemplateMethod() {}

    void operation1();
    void operation3();
    void templateMethod();//模板方法，定义一个算法的骨架，某些具体操作延迟到子类实现

protected:
    virtual bool operation2() = 0;
    virtual void operation4() = 0;
};

class ConcreteTemplateMethod : public TemplateMethod
{
public:
    bool operation2() override;
    void operation4() override;
};
void test_templateMethod();