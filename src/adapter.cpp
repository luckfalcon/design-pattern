#include "adapter.h"
#include <iostream>
using namespace std;

void Forwards::attack()
{
    cout << name << "forward attack!" << endl;
}

void Forwards::defence()
{
    cout << name << "forward defence!" << endl;
}

void Center::attack()
{
    cout << name << "center attack!" << endl;
}

void Center::defence()
{
    cout << name << "center defence!" << endl;
}

void Guards::attack()
{
    cout << name << "guards attack!" << endl;
}

void Guards::defence()
{
    cout << name << "guards defence!" << endl;
}

void ForeignCenter::jingong()
{
    cout << getName() << "外籍中锋进攻！" << endl;
}

void ForeignCenter::fangshou()
{
    cout << getName() << "外籍中锋防守！" << endl;
}

void Translator::attack()
{
    foreigncenter->jingong();
}

void Translator::defence()
{
    foreigncenter->fangshou();
}

void test_adapter()
{
    Player *b = new Forwards("巴蒂尔");
    b->attack();
    Player *m = new Guards("麦克格雷迪");
    m->attack();
    Player *ym = new Translator("姚明");
    ym->attack();
    ym->defence();
}
