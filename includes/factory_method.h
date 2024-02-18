#pragma once
#include "factory.h"
//工厂方法模式
class FactoryMethod
{
public:
    virtual ~FactoryMethod(){}
    virtual Operation *CreateOperate() = 0;
};
class Add : public FactoryMethod
{
public:
    Operation *CreateOperate() override;
};
class Sub : public FactoryMethod
{
public:
    Operation *CreateOperate() override;
};
class Mul : public FactoryMethod
{
public:
    Operation *CreateOperate() override;
};
class Div : public FactoryMethod
{
public:
    Operation *CreateOperate() override;
};
void test_factory_method();