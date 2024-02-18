#pragma once
#include <string>
// 结构
//  -------------cashsuper---------------cashcontext(不同对象的构造，调用策略)
//                   |
//      ---------------------------
//      |            |            |
//  cashnomal---cashrebate--cashreturn(策略封装)

class CashSuper // 抽象类
{
public:
    virtual double AcceptCash(double money) = 0;
    virtual ~CashSuper() {}
};
class CashNomal : public CashSuper
{
public:
    double AcceptCash(double money) override;
};
class CashRebate : public CashSuper
{
public:
    CashRebate(double rebt) : rebate(rebt) {}
    double AcceptCash(double money) override;

private:
    double rebate;
};
class CashReturn : public CashSuper
{
public:
    CashReturn(double condition, double money) : moneycondition(condition), moneyreturn(money) {}
    double AcceptCash(double money) override;

private:
    double moneycondition;
    double moneyreturn;
};
class CashContext // 策略模式和简单工厂模式的结合
{
public:
    // 通过构造函数方法，传入具体收费策略
    CashContext(int TypeNumber); // 收费类型,简单工厂的应用
    ~CashContext()
    {
        if (cs != nullptr)
            delete this->cs;
    }
    double GetResult(double money); // 根据收费策略端不同，获得计算结果
private:
    CashSuper *cs; // 声明一个cashsuper基类指针
};