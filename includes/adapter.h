#pragma once
#include <string>
/*
篮球翻译适配器
*/
class Player
{
public:
    Player(const std::string &name) : name(name) {}
    virtual void attack() = 0;  // 进攻方法
    virtual void defence() = 0; // 防守方法
protected:
    std::string name;
};
class Forwards : public Player
{
public:
    Forwards(const std::string &name) : Player(name) {}
    void attack() override;
    void defence() override;
};
class Center : public Player
{
public:
    Center(const std::string &name) : Player(name) {}
    void attack() override;
    void defence() override;
};
class Guards : public Player
{
public:
    Guards(const std::string &name) : Player(name) {}
    void attack() override;
    void defence() override;
};
// 外籍中锋
class ForeignCenter
{
public:
    void setName(const std::string &name)
    {
        this->name = name;
    }
    std::string getName() { return name; }
    void jingong();
    void fangshou();

private:
    std::string name;
};
// 翻译者
class Translator : public Player
{
public:
    Translator(const std::string &name) : Player(name)
    {
        foreigncenter = new ForeignCenter();
        foreigncenter->setName(name);
    }
    ~Translator()
    {
        if (foreigncenter != nullptr)
            delete foreigncenter;
    }
    void attack() override;
    void defence() override;

private:
    ForeignCenter *foreigncenter;
};
void test_adapter();