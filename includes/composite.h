#pragma once
#include <string>
#include <list>
/*
组合模式
----公司管理系统示例
*/

class Company
{
public:
    Company(const std::string &name) : name(name) {}
    virtual void add(Company *company) = 0;
    virtual void remove(Company *company) = 0;
    virtual void display(int depth) = 0;
    virtual void LineOfDuty() = 0; // 履行职责
protected:
    std::string name;
};
class ConcretCampany : public Company // 具体公司类 实现接口 树枝节点
{
public:
    ConcretCampany(const std::string &name) : Company(name), children(new std::list<Company *>()) {}
    ~ConcretCampany()
    {
        if (children != nullptr)
            delete children;
    }
    void add(Company *company) override;
    void remove(Company *company) override;
    void display(int depth) override;
    void LineOfDuty() override;

private:
    std::list<Company *> *children;
};
// 人力资源部与财务部类 树叶节点
// 人力资源部
class HRDepartment : public Company
{
public:
    HRDepartment(const std::string &name) : Company(name) {}
    void add(Company *company) override;
    void remove(Company *company) override;
    void display(int depth) override;
    void LineOfDuty() override;
};
// 财务部
class FinaceDepartment : public Company
{
public:
    FinaceDepartment(const std::string &name) : Company(name) {}
    void add(Company *company) override;
    void remove(Company *company) override;
    void display(int depth) override;
    void LineOfDuty() override;
};
void test_composite();