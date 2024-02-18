#include"decorator.h"
#include<iostream>
using namespace std;

void Person::show()
{
    cout << "this is " << PersonName << "'s dress show" << endl;
}

void Finery::Decorate(Person *component)
{
    Component = component;
}

void Finery::show()
{
    if (Component != nullptr)
        Component->show();
}

void Tshirts::show()
{
    Finery::show(); //先调用基类的装扮，在执行本类的装扮，从而实现组装
    cout << "Tshirts" << endl;
}

void BigTrouser::show()
{
    Finery::show();
    cout << "BigTrouser" << endl;
}

void test_decorator()
{
    Person *p = new Person("zhangsan");
    Tshirts *ts = new Tshirts();
    BigTrouser *bt = new BigTrouser();
    ts->Decorate(p);
    //ts->show();
    bt->Decorate(ts);
    bt->show();
}
