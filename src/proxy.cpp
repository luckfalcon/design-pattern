#include"proxy.h"
#include<iostream>
using namespace std;
void Pursuit::GiveDolls()
{
    cout << "Give " << mm->GetName() << " a Dolls" << endl;
}

void Pursuit::GiveFlower()
{
    cout << "Give " << mm->GetName() << " a Flower" << endl;
}

void Pursuit::GiveChocolate()
{
    cout << "Give " << mm->GetName() << " a Chocolate" << endl;
}

void proxy::GiveDolls()
{
    gg->GiveDolls();
}

void proxy::GiveFlower()
{
    gg->GiveFlower();
}

void proxy::GiveChocolate()
{
    gg->GiveChocolate();
}

void test_proxy()
{
    SchoolGirl *jiaojiao = new SchoolGirl("李娇娇");
    proxy *daili = new proxy(jiaojiao);
    daili->GiveDolls();
    daili->GiveFlower();
    daili->GiveChocolate();
}
