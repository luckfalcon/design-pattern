#include "strategy.h"
#include <iostream>
using namespace std;
CashContext::CashContext(int TypeNumber) // 工厂化
{
    switch (TypeNumber)
    {
    case 1:
    {
        std::cout << "正常收费" << std::endl;
        cs = new CashNomal();
    }
    break;
    case 2:
    {
        std::cout << "满300返100" << std::endl;
        cs = new CashReturn(300, 100);
    }
    break;
    case 3:
    {
        std::cout << "打8折" << std::endl;
        cs = new CashRebate(0.8);
    }
    break;
    default:
    {
        cs = nullptr;
        throw "systems error!";
    }
    break;
    }
}

double CashContext::GetResult(double money)
{
    return cs->AcceptCash(money);
}

// 收费策略
double CashNomal::AcceptCash(double money)
{
    return money;
}

double CashRebate::AcceptCash(double money)
{
    return money * rebate;
}

double CashReturn::AcceptCash(double money)
{
    if (money < moneycondition)
        return money;
    return money - moneyreturn;
}
void test_strategy()
{
    //选择一个收费方式
    CashContext ct(3);
    //输入收费金额及优惠信息
    cout << ct.GetResult(100) << endl;
} 