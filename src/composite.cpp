#include"composite.h"
#include<iostream>
#include<algorithm>
using namespace std;

void ConcretCampany::add(Company *c)
{
    children->push_back(c);
}

void ConcretCampany::remove(Company *c)
{
    children->remove(c);
}

void ConcretCampany::display(int depth)
{
    cout << string(depth, '-') << name << endl;
    std::for_each(children->begin(),children->end(),[depth](Company *company){company->display(depth+2);});
}

void ConcretCampany::LineOfDuty()
{
    std::for_each(children->begin(),children->end(),[](Company *company){company->LineOfDuty();});
}

void HRDepartment::add(Company *company)
{

}

void HRDepartment::remove(Company *company)
{
}

void HRDepartment::display(int depth)
{
    cout << string(depth, '-') << name << endl;
}

void HRDepartment::LineOfDuty()
{
    cout << name <<"员工招聘培训管理 " << endl;
}

void FinaceDepartment::add(Company *company)
{
}

void FinaceDepartment::remove(Company *company)
{
}

void FinaceDepartment::display(int depth)
{
    cout << string(depth, '-') << name << endl;
}

void FinaceDepartment::LineOfDuty()
{
    cout << name <<"公司财务收入管理 " << endl;
}

void test_composite()
{
    ConcretCampany *root = new ConcretCampany("北京总公司");
    root->add(new HRDepartment("总公司人力资源部"));
    root->add(new FinaceDepartment("总公司财务部"));

    ConcretCampany *comp = new ConcretCampany("上海华东分公司");
    comp->add(new HRDepartment("华东分公司人力资源部"));
    comp->add(new FinaceDepartment("华东分公司财务部"));
    root->add(comp);

    ConcretCampany *comp1 = new ConcretCampany("南京办事处");
    comp1->add(new HRDepartment("南京办事处人力资源部"));
    comp1->add(new FinaceDepartment("南京办事处财务部"));
    root->add(comp1);

    ConcretCampany *comp2 = new ConcretCampany("杭州办事处");
    comp2->add(new HRDepartment("杭州办事处人力资源部"));
    comp2->add(new FinaceDepartment("杭州办事处财务部"));
    root->add(comp2);

    cout << "结构图：" << endl;
    root->display(1);
    cout << "职责：" << endl;
    root->LineOfDuty();
}
