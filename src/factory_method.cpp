#include "factory_method.h"
#include<iostream>
using namespace std;
Operation *Add::CreateOperate()
{
    OperationAdd *op = new OperationAdd();
    return op;
}

Operation *Sub::CreateOperate()
{
    OperationSub *op = new OperationSub();
    return op;
}

Operation *Mul::CreateOperate()
{
    OperationMul *op = new OperationMul();
    return op;
}

Operation *Div::CreateOperate()
{
    OperationDiv *op = new OperationDiv();
    return op;
}

void test_factory_method()
{
    FactoryMethod *add = new Add();
    Operation *op = add->CreateOperate();
   op->setA(1);
   op->setB(2);
   cout << op->GetResult() << endl;
}
