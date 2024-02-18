#include"bridge.h"
#include<iostream>
#include<string>
using namespace std;

void ConcreteImplementorA::operationImp()
{
    cout << "ConcreteImplementorA" << endl;
}

void ConcreteImplementorB::operationImp()
{
    cout << "ConcreteImplementorB" << endl;
}

void RedefineAbstraction::SetImp(Implementor *imp)
{
    this->imp = imp;
}

void RedefineAbstraction::operation()
{
    imp->operationImp();
}

void test_bridge()
{
    Abstraction *ab = new RedefineAbstraction();
    ab->SetImp(new ConcreteImplementorA());
    ab->operation();
    ab->SetImp(new ConcreteImplementorB());
    ab->operation();
}
