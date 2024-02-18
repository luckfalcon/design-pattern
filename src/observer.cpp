#include"observer.h"
#include<iostream>

using namespace std;

void Boss::attach(Observer *ob)
{
    ol->push_back(ob);
}

void Boss::detach(Observer *ob)
{
    ol->remove(ob);
}

void Boss::notify()
{
    if (ol == nullptr)
        return;
    auto beg = ol->begin();
    while(beg!=ol->end())
    {
        (*beg)->update();
        ++beg;
    }
}

void Boss::setSubjectState(const std::string &state)
{
    this->action = state;
}

std::string Boss::getSubjectState()
{
    return action;
}

void Secretry::attach(Observer *ob)
{
    ol->push_back(ob);
}

void Secretry::detach(Observer *ob)
{
    ol->remove(ob);
}

void Secretry::notify()
{
    if (ol == nullptr)
        return;
    auto beg = ol->begin();
    while (beg != ol->end())
    {
        (*beg)->update();
        ++beg;
    }
}

void Secretry::setSubjectState(const std::string &state)
{
    this->action = state;
}

std::string Secretry::getSubjectState()
{
    return action;
}

void StockObserver::update()
{
    cout << name << ": " << sb->getSubjectState() << endl;
}

void NBAObserver::update()
{
    cout << name << ": " << sb->getSubjectState() << endl;
}

void test_observer()
{
    //主题类型,通知者类型
    Boss *boss = new Boss();
    //观察者类型，依赖于主题
    Observer *zs = new StockObserver("张三", boss);
    Observer *ls=new NBAObserver("李四",boss);
    //将观察者加入对应的主题通知对象列表
    boss->attach(zs);
    boss->attach(ls);
    //主题状态发生改变
    boss->setSubjectState("我胡汉三回来了！");
    //发布通知
    boss->notify();
    //主题再次发生改变,不通知李四
    boss->setSubjectState("天王盖地虎！");
    boss->detach(ls);
    boss->notify();
}
