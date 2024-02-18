#pragma once
#include <string>
//简单工厂模式
class Operation
{
public:
virtual ~Operation(){}
    double GetA() { return NumberA; }
    double GetB() { return NumberB; }
    void setA(double numA) { NumberA = numA; }
    void setB(double numB) { NumberB = numB; }
    virtual double GetResult()
    {
        double result = 0;
        return result;
    }

private:
    double NumberA = 0;
    double NumberB = 0;
};
class OperationAdd : public Operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = GetA() + GetB();
        return result;
    }
};
class OperationSub : public Operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = GetA() - GetB();
        ;
        return result;
    }
};
class OperationMul : public Operation
{
public:
    double GetResult() override
    {
        double result = 0;
        result = GetA() * GetB();
        return result;
    }
};
class OperationDiv : public Operation
{
public:
    double GetResult() override
    {
        double result = 0;
        if (GetB() == 0)
            throw "numberB can be zero!";
        else
            result = GetA() / GetB();
        return result;
    }
};
class OperationFactory
{
public:
    static Operation *CreateOperate(const char operate);
};