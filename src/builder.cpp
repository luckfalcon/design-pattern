#include"builder.h"
#include<iostream>

using namespace std;

void PersonDirector::createPerson(PersonBuilder*pb)
{
    pb->buildHead();
    pb->buildBody();
    pb->buildHand();
    pb->buildFoot();
}

void PersonThinBuilder::buildHead()
{
    pp->setHead("thin-head");
}

void PersonThinBuilder::buildBody()
{
    pp->setBody("thin-body");
}

void PersonThinBuilder::buildHand()
{
    pp->setHand("thin-hand");
}

void PersonThinBuilder::buildFoot()
{
    pp->setFoot("thin-foot");
}


void PersonFatBuilder::buildHead()
{
     pp->setHead("fat-head");
}

void PersonFatBuilder::buildBody()
{
    pp->setBody("fat-body");
}

void PersonFatBuilder::buildHand()
{
    pp->setHand("fat-hand");
}

void PersonFatBuilder::buildFoot()
{
    pp->setFoot("fat-foot");
}

void PersonProduct::show()
{
    cout << name << endl;
    cout << head << " " << body << " " << hand << " " << foot << endl;
}

void test_builder()
{
    PersonDirector *pd = new PersonDirector();
    PersonBuilder *b1 = new PersonThinBuilder("张三");
    PersonBuilder *b2 = new PersonFatBuilder("李四");
    pd->createPerson(b1);
    pd->createPerson(b2);
    PersonProduct *p1 = b1->getPersonProduct();
    p1->show();
    PersonProduct *p2 = b2->getPersonProduct();
    p2->show();
}
