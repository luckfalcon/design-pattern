#include"event.h"
#include<iostream>

using namespace std;


void Bos::notify()
{
    if (update == nullptr)
        return;
    (*update)();
}

void Bos::setSubState(const std::string &state)
{
    action = state;
}

std::string Bos::getSubState()
{
    return action;
}

void StockOer::closeStockMarket()
{
    cout << name << " " << sb->getSubState() << endl;
}
void closeStockMarket(StockOer*soer)
{
    soer->closeStockMarket();
}

void NBAOer::closeNBADirectSeeding()
{
    cout << name << " " << sb->getSubState() << endl;
}
void closeNBADirectSeeding(NBAOer *noer)
{
    noer->closeNBADirectSeeding();
}
void test_event()
{
    // Bos *huhansan = new Bos();
    // StockOer *tongshi1 = new StockOer("张三", huhansan);
    // closeStockMarket(tongshi1);
    // huhansan->update = new Eventhandler(tongshi1->closeStockMarket); // 类成员函数无法
    // huhansan->setSubState("老板回来了！");
    // huhansan->notify();
}

