#include "memento.h"
#include<iostream>
using namespace std;
void GameRole::initRole()
{
    this->vit = 100;
    this->atk = 100;
    this->def = 100;
}

void GameRole::fight()
{
    this->vit -= 10;
    this->atk -= 10;
    this->def -= 10;
}

void GameRole::showState()
{
    cout << "当前游戏角色: " << this->roleName << endl;
    cout << "生命值: " << vit << endl;
    cout << "攻击力: " << atk << endl;
    cout << "防御力: " << def << endl;

}

void GameRole::recoveryState(RoleStateMemento *memento)
{
    this->vit = memento->getVit();
    this->atk = memento->getAtk();
    this->def = memento->getDef();
}

void test_memento()
{
    GameRole *lixiaoyao = new GameRole("李逍遥");
    lixiaoyao->initRole();
    lixiaoyao->showState();
    RolseStateCaretaker *taker = new RolseStateCaretaker();
    taker->setMemento(lixiaoyao->saveState());
    lixiaoyao->fight();
    lixiaoyao->showState();
    lixiaoyao->recoveryState(taker->getMemento());
    lixiaoyao->showState();
}
