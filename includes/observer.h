#pragma once
#include<list>
#include<string>

class Subject;
class Observer // 抽象观察者类
{
public:
    Observer():sb(nullptr){}
    virtual ~Observer(){}
    
    Observer(const std::string &name, Subject *sb) : name(name), sb(sb) {}
    virtual void update() = 0;

protected:
    std::string name;
    Subject *sb;
};
class Subject//抽象主题类(通知者)
{
public:
    virtual ~Subject() {}
    virtual void attach(Observer*ob) = 0;
    virtual void detach(Observer*ob) = 0;
    virtual void notify() = 0;
    virtual void setSubjectState(const std::string &state) = 0;
    virtual std::string getSubjectState() = 0;
};
class Boss : public Subject
{
public:
    Boss() : ol(new std::list<Observer *>()) {}
    ~Boss(){
        if (ol != nullptr)
            delete ol;
    }
    void attach(Observer *ob) override;
    void detach(Observer *ob) override;
    void notify() override;
    void setSubjectState(const std::string &state)override;
    std::string getSubjectState()override;
private:
    std::string action;//主题状态
    std::list<Observer*> *ol;
};
class Secretry : public Subject
{
public:
    Secretry() : ol(new std::list<Observer *>()) {}
    ~Secretry(){
        if (ol != nullptr)
            delete ol;
    }
    void attach(Observer *ob) override;
    void detach(Observer *ob) override;
    void notify() override;
    void setSubjectState(const std::string &state) override;
    std::string getSubjectState() override;
private:
    std::string action;
    std::list<Observer *> *ol;
};
//看股票的同事
class StockObserver : public Observer
{
    public:
        StockObserver(const std::string &name, Subject *sb) : Observer(name, sb) {}
        void update() override;
};
//看NBA的同事
class NBAObserver : public Observer
{
    public:
        NBAObserver(const std::string &name, Subject *sb) : Observer(name, sb) {}
        void update() override;
};
//client
void test_observer();