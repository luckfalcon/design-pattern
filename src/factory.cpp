#include "factory.h"
#include<iostream>
Operation *OperationFactory::CreateOperate(const char operate)
{
    Operation *oper = nullptr;
    switch (operate)
    {
    case '+':
        oper = new OperationAdd();
        break;
    case '-':
        oper = new OperationSub();
        break;
    case '*':
        oper = new OperationMul();
        break;
    case '/':
        oper = new OperationDiv();
        break;
        default:
        throw "systems error!";
        break;
    }
    return oper;
}
void test_factory()
{
    Operation *oper = OperationFactory().CreateOperate('+');
    oper->setA(1);
    oper->setB(2);
    double result = oper->GetResult();
    std::cout << result << std::endl;
} 