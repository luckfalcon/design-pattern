#include "facade.h"
#include <iostream>

using namespace std;

void SubSystemA::methodCall()
{
    cout << "can subsystemA" << endl;
}
void SubSystemA::methodRelease()
{
    cout << "release subsystemA" << endl;
}
void SubSystemB::methodSet()
{
    cout << "set subsystemB" << endl;
}
void SubSystemB::methodUnset()
{
    cout << "unset subsystemB" << endl;
}
void SubSystemC::methodInstall()
{
    cout << "install subsystemC" << endl;
}

void SubSystemC::methodUnstall()
{
    cout << "unstall subsystemC" << endl;
}
Facade::~Facade()
{
    if (sbsA != nullptr)
        delete sbsA;
    if (sbsB != nullptr)
        delete sbsB;
    if (sbsC != nullptr)
        delete sbsC;
}

void Facade::facdeMethodA()
{
    cout << "use methodA:" << endl;
    sbsA->methodCall();
    sbsB->methodSet();
    sbsC->methodInstall();
}

void Facade::facdeMethodB()
{
    cout << "use methodB:" << endl;
    sbsA->methodRelease();
    sbsB->methodUnset();
    sbsC->methodUnstall();
}

void test_facade()
{
    Facade *f = new Facade();
    f->facdeMethodA();
    f->facdeMethodB();
}
