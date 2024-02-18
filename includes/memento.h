#pragma once
#include <string>
/*
游戏进度备忘录
*/
// 角色状态存储箱
class RoleStateMemento
{
public:
    RoleStateMemento(int vit, int atk, int def) : vit(vit), atk(atk), def(def) {}
    void setVit(int vit) { this->vit = vit; }
    int getVit() { return vit; }
    void setAtk(int atk) { this->atk = atk; }
    int getAtk() { return atk; }
    void setDef(int def) { this->def = def; }
    int getDef() { return def; }

private:
    int vit;
    int atk;
    int def;
};
// 游戏角色
class GameRole
{
public:
    GameRole(const std::string &name) : roleName(name), vit(0), atk(0), def(0) {}
    void initRole();
    // 保存角色状态
    RoleStateMemento *saveState() { return new RoleStateMemento(vit, atk, def); }
    void fight();
    void showState();
    // 恢复角色状态
    void recoveryState(RoleStateMemento *memento);

private:
    int vit; // 生命力
    int atk; // 攻击力
    int def; // 防御力
    std::string roleName;
};

// 角色状态管理者
class RolseStateCaretaker
{
public:
~RolseStateCaretaker(){
    if (memento != nullptr)
        delete memento;
}
    RoleStateMemento *getMemento() { return memento; }
    void setMemento(RoleStateMemento *memento) { this->memento = memento; }

private:
    RoleStateMemento *memento;
};
void test_memento();