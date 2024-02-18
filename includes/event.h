#pragma once
#include <string>
#include <list>
#include"eventhandle.h"

/*特殊的观察者模式
基于事件，发出通知
*/


// 通知者接口

class Sub
{
public:
    Sub() {}
    virtual ~Sub() {}
    virtual void setSubState(const std::string &state) = 0;
    virtual std::string getSubState() = 0;
    virtual void notify() = 0;
};

// 通知者
class Bos : public Sub
{
public:
    Eventhandler *update;

    Bos() : action(), update(nullptr) {}
    void notify() override;
    void setSubState(const std::string &state) override;
    std::string getSubState() override;

private:
    std::string action;
};

// 观察者
class StockOer
{
public:
    StockOer(const std::string &name, Sub *sb) : name(name), sb(sb) {}
    void closeStockMarket();
private:
    Sub *sb;
    std::string name;
};
void closeStockMarket(StockOer*);
class NBAOer
{
public:
    NBAOer(const std::string &name, Sub *sb) : name(name), sb(sb) {}
    void closeNBADirectSeeding(); // 关闭NBA直播
private:
    Sub *sb;
    std::string name;
};
void closeNBADirectSeeding(NBAOer *);

void test_event();